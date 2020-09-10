#pragma warning(disable:4996)
#include<stdio.h>

/*
트리 순회를 재귀 함수로 구현하여야 함.
*/

typedef struct _TreeNode {
	char value;
	struct _TreeNode* leftChild;
	struct _TreeNode* rightChild;
}TreeNode;

TreeNode* rootAddress;

void initializeNode(TreeNode* node, char val);//구조체 변수 초기화
void inputValue(void);
TreeNode* searchNode(TreeNode* nodeToFind, char val);//전달받은 알파벳과 동일한 알파벳을 가진 TreeNode의 주소 반환
void nodeLinking(char parentVal, char leftChildVal, char rightChildVal);//부모 노드와 자식 노드 연결, 알파벳 입력
void treeInOrder(TreeNode* currentNode);//재귀적으로 중위 순회를 하며 값을 출력하는 함수

void initializeNode(TreeNode* node, char val) {
	node->value = val;
	node->leftChild = NULL;
	node->rightChild = NULL;
}

void inputValue(void) {
	int n;

	scanf("%d", &n);//노드의 개수
	getchar();

	for (int i = 0; i < n; i++) {
		char parent, leftChild, rightChild;
		scanf("%c %c %c", &parent, &leftChild, &rightChild);
		getchar();
		nodeLinking(parent, leftChild, rightChild);
	}
}

TreeNode* searchNode(TreeNode* nodeToFind, char val) {
	if (nodeToFind == NULL || nodeToFind->value == val)
		return nodeToFind;

	//nodeToFind가 NULL이 아니고 value값도 다르다면
	TreeNode* fit = searchNode(nodeToFind->leftChild, val);
	if (fit == NULL)
		fit = searchNode(nodeToFind->rightChild, val);
	return fit;
}

void nodeLinking(char parentVal, char leftChildVal, char rightChildVal) {
	TreeNode* parentNode = searchNode(rootAddress, parentVal);
	//입력된 문자가 . 이 아니라면 노드 생성 후 부모 노드와 연결
	if (leftChildVal != '.') {
		TreeNode* leftNode = (TreeNode*)(malloc(sizeof(TreeNode)));
		initializeNode(leftNode, leftChildVal);
		parentNode->leftChild = leftNode;
	}
	if (rightChildVal != '.') {
		TreeNode* rightNode = (TreeNode*)(malloc(sizeof(TreeNode)));
		initializeNode(rightNode, rightChildVal);
		parentNode->rightChild = rightNode;
	}
}

void treeInOrder(TreeNode* currentNode) {
	if (currentNode->leftChild)
		treeInOrder(currentNode->leftChild);
	printf("%c", currentNode->value);
	if (currentNode->rightChild)
		treeInOrder(currentNode->rightChild);
}

int main(void) {
	rootAddress = (TreeNode*)(malloc(sizeof(TreeNode)));
	initializeNode(rootAddress, 'A');
	inputValue();
	treeInOrder(rootAddress);
	return 0;
}
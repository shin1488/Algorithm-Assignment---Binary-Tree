#pragma warning(disable:4996)
#include<stdio.h>

/*
Ʈ�� ��ȸ�� ��� �Լ��� �����Ͽ��� ��.
*/

typedef struct _TreeNode {
	char value;
	struct _TreeNode* leftChild;
	struct _TreeNode* rightChild;
}TreeNode;

TreeNode* rootAddress;

void initializeNode(TreeNode* node, char val);//����ü ���� �ʱ�ȭ
void inputValue(void);
TreeNode* searchNode(TreeNode* nodeToFind, char val);//���޹��� ���ĺ��� ������ ���ĺ��� ���� TreeNode�� �ּ� ��ȯ
void nodeLinking(char parentVal, char leftChildVal, char rightChildVal);//�θ� ���� �ڽ� ��� ����, ���ĺ� �Է�
void treeInOrder(TreeNode* currentNode);//��������� ���� ��ȸ�� �ϸ� ���� ����ϴ� �Լ�

void initializeNode(TreeNode* node, char val) {
	node->value = val;
	node->leftChild = NULL;
	node->rightChild = NULL;
}

void inputValue(void) {
	int n;

	scanf("%d", &n);//����� ����
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

	//nodeToFind�� NULL�� �ƴϰ� value���� �ٸ��ٸ�
	TreeNode* fit = searchNode(nodeToFind->leftChild, val);
	if (fit == NULL)
		fit = searchNode(nodeToFind->rightChild, val);
	return fit;
}

void nodeLinking(char parentVal, char leftChildVal, char rightChildVal) {
	TreeNode* parentNode = searchNode(rootAddress, parentVal);
	//�Էµ� ���ڰ� . �� �ƴ϶�� ��� ���� �� �θ� ���� ����
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
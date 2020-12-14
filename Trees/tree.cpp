#include<bits/stdc++.h>

using namespace std;

int main() {

	struct Node {
		int key;
		struct Node *left, *right;

		Node(int key) {
			this->key = key;
			left = right = NULL;
		}
	};

	return 0;
}
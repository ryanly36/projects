#include "BSTree.h"
#include <iostream>
#include <fstream>
using namespace std;

BSTree::BSTree() {
    root = nullptr;

}

BSTree::~BSTree() {
    if(root != nullptr) {
        delete(root->left);
        delete(root->right);
        delete root;
    }
}

int BSTree::height(const string& key) const {
    Node* temp;
    temp = root;
    int height = 0;
	
    if(temp == nullptr) {
        return -1;
    }
    if(!search(key)) {
        return -1;
    }

    while(temp != nullptr) {
        if(temp->data == key) {
            break;
        }
        if(temp->data < key) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    // else {
    //     while(temp != nullptr) {
    //         if(temp->data != key) {
    //             if(temp->data > key) {
    //                 temp = temp->left;
    //                 temp->left = temp->left->left;
    //                 height++;
    //             }
    //             else {
    //                 temp = temp->right;
    //                 temp->right = temp->right->right;
    //                 height++;
    //             }
    //         }
    //     }
    // }
    return height;
}

void BSTree::insert(const string &newString){
    
    if(newString == "/n") {
        cout << "ERROR: cannot create node with no data" << endl;
        return;
    }
    Node *newNode = new Node(newString);
    if(root == nullptr) {
        root= newNode;
        root->right = nullptr;
        root->left = nullptr;
        root->count++;
    }
    else {
        Node *tempNode = root;
        while(tempNode != nullptr) {
            if(newNode->data == tempNode->data){
                tempNode->count++;
                return;
            }
            if(newNode->data < tempNode->data) {
                if(tempNode->left == nullptr) {
                    tempNode->left = newNode;
                    newNode->count++;
                    tempNode = nullptr;
                }
                else {
                    tempNode = tempNode->left;
                }
            }
            else {
                if(newNode->data > tempNode->data) {
                    if(tempNode->right == nullptr) {
                        tempNode->right = newNode;
                        newNode->count++;
                        tempNode = nullptr;
                    }
                }
            }
        }
    }

}

void BSTree::remove(const string &key) {
    Node* curr = root;
        if(curr->count > 1) {
            remove(curr, curr->data);
        }
        remove(curr, key);

}

Node* BSTree::remove(Node* node, const string &key) {
    Node* par = nullptr;
    Node* curr = node;

    while(curr != nullptr) {
         if(curr->data == key) {
            if(!curr->left && !curr->right) {
                if(!par) {
                    root = nullptr;
                }
                else if(par->left == curr) {
                    par->left = nullptr;
                }
                else {
                    par->right = nullptr;
                }
            }
            else if (!curr->left && curr->right) {
                if(!par) {
                    root = curr->right;
                }
                else if (par->left == curr) { 
                    par->left = curr->right;
                }
                else {
                    par->right = curr->right;
                }
            }
            else {
                Node* successor = curr->right;
                while(successor->left != nullptr) {//
                    successor = successor->left;//
                }
                Node* temp = successor;
                remove(root, temp->data);
                curr->data = temp->data;
            }
            return curr;
        }
        else if(curr->data < key) {
            par = curr;
            curr = curr->right;
        }
        else {
            par = curr;
            curr = curr->left;
        }
    }
    return curr;
}

string BSTree::smallest() const {
	string smallest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->left != nullptr) {
			currNode = currNode->left;
		}
		smallest = currNode->data;
	}
	return smallest;
}

string BSTree::largest() const {
	string largest = "";
	if (root != nullptr) {
		Node* currNode = root;
		while (currNode->right != nullptr) {
			currNode = currNode->right;
		}
		largest = currNode->data;
	}
	return largest;
}
void BSTree::inOrder() const {
	inOrder(root);
}

void BSTree::postOrder() const {
	postOrder(root);
}

void BSTree::preOrder() const {
	preOrder(root);
}
        /* Printing */
        /* For all printing orders, each node should be displayed as follows:
           <string> (<count>)
           e.g. goodbye(1), Hello World(3)
           */
void BSTree::postOrder(Node* node) const {
	if (node != nullptr) {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << "(" << node->count << "), ";
	}

}


void BSTree::preOrder(Node* node) const {
	if (node != nullptr) {
		cout << node->data << "(" << node->count << "), ";
		preOrder(node->left);
		preOrder(node->right);
	}
	
}


void BSTree::inOrder(Node* node) const {
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->data << "(" << node->count << "), ";
		inOrder(node->right);
	}
	
}


 bool BSTree::search(const string &key) const {

  Node *check = search(this->root, key);
  if (check) {
    return true;
  }
  else {
    return false;
  }

}

Node *BSTree::search(Node *node, const string &key) const {
  if (!node) {
    return nullptr;
  }

  else if (node->data == key) {
    return node;
  }

  else if (node->data > key) {
    return search(node->left, key);
  }

  else {
    return search(node->right, key);
  }

}

// void BSTree::visualizeTree(ofstream &fout, Node* node) {
// 	if (node != nullptr) {
// 		if (node->left != nullptr) {
// 			fout << node->count << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->data << "\"" << "];" << endl;
// 			fout << node->left->count << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->left->data << "\"" << "];" << endl;
// 			fout << node->count << " -> " << node->left->count << endl;
// 			if (node->right != nullptr) {
// 				fout << node->right->count << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->right->data << "\"" << "];" << endl;
// 				fout << node->count << " -> " << node->right->count << endl;
// 				visualizeTree(fout, node->left);
// 				visualizeTree(fout, node->right);
// 			}
// 			else {
// 				visualizeTree(fout, node->right);
// 			}
// 		}
// 		else {
// 			if (node->right != nullptr) {
// 				fout << node->count << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->data << "\"" << "];" << endl;
// 				fout << node->right->count << " [ color = red, peripheries=2, style = filled, label = " << "\"" << node->right->data << "\"" << "];" << endl;
// 				fout << node->count << " -> " << node->right->data << endl;
// 				visualizeTree(fout, node->right);
//                 visualizeTree(fout, node->left);
// 			}
// 		}
// 	}
    
// }
// void BSTree::visualizeTree(const string &outputFilename) {
//     ofstream outFS(outputFilename.c_str());
//     if(!outFS.is_open()){
//         cout<<"Error opening "<< outputFilename<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     visualizeTree(outFS,root);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
    
// }
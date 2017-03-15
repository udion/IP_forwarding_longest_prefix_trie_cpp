#include <iostream>
#include <bits/stdc++.h>
#include "trie.h"

using namespace std;

//The definition of the member function of the t_node class

trie::trie(){
	root = new t_node;
	root->netAval = "empty";
	root->netMval = "empty";
	root->netAM = "empty";
	root->zeroside = NULL;
	root->oneside = NULL;
}

void trie::destroy_trie(t_node* node){
	if(node != NULL){
		destroy_trie(node->zeroside);
		destroy_trie(node->oneside);
		delete node;
	}
}

void trie::insert(string netA, string netM){
	int read_upto;
	if(netM.find('0') != string::npos)
		read_upto = netM.find('0');
	else
		read_upto = netM.length();
	t_node* it = root;
	
	for(int i = 0; i<read_upto; i++){
		string r(1, netA[i]); //side to go to
		int side = stoi(r);
		if(i < read_upto -1){
			if(side == 1){
				if(it->oneside == NULL){		//if a node doesnt exist this side then create and join
					t_node* newnode = new t_node;
					newnode->netAval = netA.substr(0,i+1);
					newnode->netMval = netM;
					newnode->zeroside = NULL;
					newnode->oneside = NULL;
					newnode->finalnode = false;
					newnode->netAM = "00000000000000000000000000000000";//dummy value
					it->oneside = newnode;
					it = it->oneside;
				}
				else{							//if the node does exist but is not going to be final node then just move
					it = it->oneside;
				}
			}
			else{
				if(it->zeroside == NULL){
					t_node* newnode = new t_node;
					newnode->netAval = netA.substr(0,i+1);
					newnode->netMval = netM;
					newnode->zeroside = NULL;
					newnode->oneside = NULL;
					newnode->finalnode = false;
					newnode->netAM = "00000000000000000000000000000000";//dummy value
					it->zeroside = newnode;
					it = it->zeroside;
				}
				else{
					it = it->zeroside;
				}
			}
		}
		else{								//if this node is going to be final node then
			if(side == 1){
				if(it->oneside == NULL){	//if it doesnt exist then create one and declare it final
					t_node* newnode = new t_node;
					newnode->netAval = netA.substr(0,i+1);
					newnode->netMval = netM;
					newnode->zeroside = NULL;
					newnode->oneside = NULL;
					newnode->finalnode = true;
					bitset<32>tempAM = bitset<32>(netA) & bitset<32>(netM);
					newnode->netAM = tempAM.to_string();
					it->oneside = newnode;
					it = it->oneside;
				}
				else{						//if it does exist then move to that place and declare it final
					it = it->oneside;
					it->netMval = netM;
					bitset<32>tempAM = bitset<32>(netA) & bitset<32>(netM);
					it->netAM = tempAM.to_string();
					it->finalnode = true;
				}
			}
			else{
				if(it->zeroside == NULL){
					t_node* newnode = new t_node;
					newnode->netAval = netA.substr(0,i+1);
					newnode->netMval = netM;
					newnode->zeroside = NULL;
					newnode->oneside = NULL;
					newnode->finalnode = true;
					bitset<32>tempAM = bitset<32>(netA) & bitset<32>(netM);
					newnode->netAM = tempAM.to_string();
					it->zeroside = newnode;
					it = it->zeroside;
				}
				else{
					it = it->zeroside;
					it->netMval = netM;
					bitset<32>tempAM = bitset<32>(netA) & bitset<32>(netM);
					it->netAM = tempAM.to_string();
					it->finalnode = true;
				}
			}
		}
	}
}
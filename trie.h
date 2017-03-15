#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////
//creating a data-structure which will act as my trie
//with the basic functionalities of trie
struct t_node{
	string netAval; //it'll store netaddress sofar
	string netMval; //it'll store netmask
	string netAM; 	//it will store and of netmask and netaddress
	bool finalnode;
	t_node* zeroside;
	t_node* oneside;
};

class trie{
public:
	trie();
	void destroy_trie(t_node* node);
	void insert(string netA, string netM);
	t_node* root;	
};
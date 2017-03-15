#include <iostream>
#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

int main(){
	//very subtle point that rtable should not be defined as map because in map the keys are unique and correspond to only one values
	vector<pair<string,string> >rtable;
	string inp_line;

	getline(cin,inp_line);
	while(inp_line != "default"){
		if (inp_line != "NetworkAddress Netmask"){
			string netA = inp_line.substr(0, inp_line.find(' '));
			string netM = inp_line.substr(inp_line.find(' ')+1);
			rtable.push_back(make_pair(netA,netM));
		}
		getline(cin,inp_line);
	}

	//printtable(rtable);
	//Now trie is built using rtable
	//buildTrie will return the root of the trie after making trie

	t_node* troot = new t_node;
	troot = buildTrie(rtable);
	
	if(troot == NULL) cout<<"dump"<<endl;
	//cout<<"trie built!!!"<<endl;
	//now for every input ip in the quiery i have to look for it in the trie by taking 
	//AND with the netmask
	int q;	cin>>q;
	getline(cin,inp_line);
	for(int i=0;i<q;i++){
		getline(cin,inp_line);
		
		string ipbin = ip2bin(inp_line).to_string();
		vector<t_node*> matched;
		t_node* curr = new t_node;
		//now that i have the IP i have to start moving in Trie
		curr = troot;
		bool ippresent = true;
		for(int k=0;k<32;k++){
			if(ipbin[k] == '0'){
				if(curr->zeroside != NULL){
		//			cout<<"zeroside is not null"<<endl;
					curr = curr->zeroside;
					if(curr->finalnode){
		//				cout<<"its a final node"<<endl;
						bitset<32> str = bitset<32>(ipbin) & bitset<32>(curr->netMval);
						if (str == bitset<32>(curr->netAM)){
							matched.push_back(curr);
		//					cout<<"matched...yay"<<endl;
						}
							
					}
				}
				else{
		//			cout<<"zeroside is null"<<endl;
					ippresent = false;
				}	
			}
			else{
				if(curr->oneside != NULL){
		//			cout<<"oneside is not null"<<endl;
					curr = curr->oneside;
					if(curr->finalnode){
		//				cout<<"its a final node"<<endl;
						bitset<32> str = bitset<32>(ipbin) & bitset<32>(curr->netMval);
						if (str == bitset<32>(curr->netAM)){
							matched.push_back(curr);
		//					cout<<"matched...yay"<<endl;
						}
					}
				}
				else{
		//			cout<<"oneside is null"<<endl;
					ippresent = false;
				}
			}
		}

		//now I have all the nodes to which this particular ipmatches in the vector
		//I just have to find out the node which has the match with longest network address
		if(matched.empty() && !(ippresent)){
			cout<<inp_line<<" "<<"default"<<endl;
		}
		else{
			t_node* final_ptr = longestPrefix(matched);
			cout<<inp_line<<" "<<bin2ip(bitset<32>(final_ptr->netAM))<<" "<<bin2ip(bitset<32>(final_ptr->netMval))<<endl;
		}	
	}
}
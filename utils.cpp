#include <iostream>
#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

void printtable(vector<pair<string,string> >mp){
	cout<<"NetworkAddress Netmask"<<endl;
	for(auto it = mp.begin(); it != mp.end(); it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<"default"<<endl;
}

bitset<32> ip2bin(string ip){
	string ip_bin="";
	int point = ip.find('.');
	int s=0;
	while(point != string::npos){
		ip_bin += bitset<8>(stoi(ip.substr(s,point))).to_string();
		s = point+1;
		point = ip.find('.', s);
		if(point == string::npos){
			ip_bin += bitset<8>(stoi(ip.substr(s,ip.length()))).to_string();
		}
	}
	return bitset<32>(ip_bin);
}

string bin2ip(bitset<32> ip){
	string numip="";
	string s = ip.to_string();
	for(int i=7; i<=31; i = i+8){
		unsigned long num = bitset<8>(s.substr(i-7, i+1)).to_ulong();
		if(i != 31)
			numip += (to_string(num)+'.');
		else
			numip += to_string(num);
	}
	return numip;
}

t_node* buildTrie(vector<pair<string, string> >rtable){
	trie* T;
	T = new trie;
	for(auto it = rtable.begin(); it != rtable.end(); it++){
		string netA = ip2bin(it->first).to_string();
		string netM = ip2bin(it->second).to_string();
		T->insert(netA, netM);
	}
	return T->root;
}


t_node* longestPrefix(vector<t_node*> v){
	t_node* curr = *v.begin();
	for(auto p = v.begin(); p != v.end(); p++){
		if((*p)->netAval.length() > curr->netAval.length())
			curr = *p;
	}
	return curr;
}
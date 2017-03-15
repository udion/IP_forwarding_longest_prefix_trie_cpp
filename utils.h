#include <iostream>
#include <bits/stdc++.h>
#include "trie.h"

using namespace std;

void printtable(vector<pair<string,string> >);
bitset<32> ip2bin(string);
string bin2ip(bitset<32>);
t_node* buildTrie(vector<pair<string, string> >);
t_node* longestPrefix(vector<t_node*>);

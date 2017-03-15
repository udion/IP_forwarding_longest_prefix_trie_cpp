# IP_forwarding_longest_prefix_trie_cpp
This is an c++ implementation of routing of packets based on IP given a routing table, using trie data structure to make searching faster.

As input first a forwarding table will be given and then the number of search queries followed by the given number of IP's, as in the following example:

~~~
NetworkAddress Netmask
203.0.0.0 255.0.0.0
178.23.99.0 255.255.255.0
181.51.36.0 255.255.255.0
135.42.64.0 255.255.192.0
178.23.99.80 255.255.255.240
135.42.96.0 255.255.224.0
181.51.0.0 255.255.128.0
181.51.0.0 255.255.192.0
default
8
178.23.99.45
203.200.1.6
135.42.72.40
135.42.104.0
181.51.36.35
181.51.67.54
181.51.35.89
154.67.34.9
~~~
each table will have the last entry as the default one, which will be matched to an IP if nothing else is matched in the table. This is followed by 8 which represents the number of queries and then the IP's.

The result will be the particular IP matched with the particluar of the routing table as displayed in the example below:

~~~
178.23.99.45 178.23.99.0 255.255.255.0      
203.200.1.6 203.0.0.0 255.0.0.0  
135.42.72.40 135.42.64.0 255.255.192.0      
135.42.104.0 135.42.96.0 255.255.224.0
181.51.36.35 181.51.36.0 255.255.255.0    
181.51.67.54 181.51.0.0 255.255.128.0    
181.51.35.89 181.51.0.0 255.255.192.0    
154.67.34.9 default
~~~

The search algorithm is based on trie data-structure which chooses the one matched network address which is the longest in length out of all the matched network addresses.

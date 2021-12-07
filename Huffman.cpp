#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map <char , int> getFrequency(string message) {
	unordered_map <char , int> freq;
	for (const char &c : message) {
		freq[c] += 1;
	}
	return freq;
}
struct Character {
	char element;
	int frequency;
	int index;
	int leftChild;
	int rightChild;
	Character(char x , int f, int idx) :  Character(x, f, idx, idx, idx) {

	}
	Character(char x , int f, int idx , int lChild , int rChild) :  element(x) , frequency(f) , index(idx) , leftChild(lChild) , rightChild(rChild) {}
	bool operator< (const Character &c) {
		return frequency < c.frequency;
	}
	bool operator> (const Character &c) {
		return frequency > c.frequency;
	}
};
struct comparator {
	bool operator()(const Character &a , const Character &b) {
		return a.frequency >= b.frequency;
	}
};
int main() {
	string message;
	cin >> message;
	unordered_map <char , int> frequency_of_char = getFrequency(message);
	vector <Character> huffman;
	for (const pair <char, int> &p : frequency_of_char) {
		huffman.push_back(Character(p.first, p.second, huffman.size()));
	}
	priority_queue <Character, vector <Character>, comparator> pq;
	for (Character &x : huffman) {
		pq.push(x);
	}
	while (pq.size() != 1) {
		Character a = pq.top(); pq.pop();
		Character b = pq.top(); pq.pop();
		Character c ('#', a.frequency + b.frequency, huffman.size(), a.index , b.index);
		huffman.push_back(c);
		pq.push(c);
	}
	stack <pair <int, string> > stk;
	stk.push({huffman.size() - 1, ""});
	unordered_map <int , string> huffman_codes;
	while (stk.size()) {
		auto ele = stk.top(); stk.pop();
		int index = ele.first;
		string code = ele.second;
		if (index == huffman[index].leftChild) {
			huffman_codes[index] = code;
			continue;
		}
		stk.push({(huffman[index].leftChild), code + "0"});
		stk.push({(huffman[index].rightChild), code + "1"});
	}
	for (auto &x : huffman_codes) {
		cout << x.first << " " << huffman[x.first].element << " " << x.second << endl;
	}
	return 0;
}
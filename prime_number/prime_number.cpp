/*
Link: https://www.cnblogs.com/linyujun/p/5198832.html
*/
#include "../template.hpp"

/*
Note: only for non-negative number
Complexity: O(log(min(a,b)))
*/
ulld fast_mul(ulld a, ulld b)
{
	ulld max = a>b ? a : b;
	ulld min = max==b ? a : b;
	ulld ans = 0;
	
	while(min){
		if(min & 1)
			ans += max;
		max += max;
		min >>= 1;
	}
	return ans;
}

/*
Note: only for non-negative number of power
Complexity: O(log(min(a,b)))
*/
ulld fast_pow(lld a, ulld b)
{
	ulld max = a>b ? a : b;
	ulld min = max==b ? a : b;
	ulld ans = 1;

	while(min){
		if(min & 1)
			ans = fast_mul(ans, max);
		max = fast_mul(max, max);
		min >>= 1;
	}
	return ans;
}

/*
Complexity: O(sqrt(n))
Input: lld num
Output: true for prime
*/
bool prime(lld num)
{
	if(num < 2)
		return true;
	for(lld i=2; fast_pow(i,2)<num; i++)
		if(!(num%i))
			return false;
	return true;
}
/*
Complexity: O(sqrt(n))
Input: lld num, vector<int> &table
Output: none
*/
void primeTable(lld num, vector<lld> &table)
{
	bool prime[num]; memset((void*)prime, 1, num);
	lld i;
	for(i=2; fast_pow(i,2) < num; i++){
		if(prime[i]){
			table.push_back(i);
			for(lld j=i; j*i<num; j++){
				prime[j*i] = false;
			}
		}
	}
	for(; i<num; i++){
		if(prime[i])
			table.push_back(i);
	}
}
/*
Input: num, table is prime table, fact is a map of prime factor
Output: none
*/
void primeFact(lld num, vector<lld> &table, map<lld, lld> &fact)
{
	for(auto m : table){
		if(!num)
			break;
		while(!(num%m)){
			num /= m;
			if(fact.find(m) != fact.end()){
				++fact[m];
			}
			else{
				fact.insert({m, 1});
			}
		}
	}
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
	int mode; //sprintf(argv[1], "%d", mode);
	lld num; //sprintf(argv[2], "%lld", num);
	cin >> mode;
	vector<lld> table;
	map<lld, lld> fact;

    switch(mode){
		case 0:
			while(cin >> num){
				if(prime(num))
					cout << num << " is a prime" << endl;
				else
					cout << num << " is not a prime" << endl;
			}
			break;
		case 1:
			cin >> num;
			cout << num << " prime table" << endl;
			primeTable(num, table);
			for(auto m : table)
				cout << m << endl;
			break;
		case 2:
			cin >> num;
			cout << num << " prime factorization" << endl;
			if(prime(num)){
				cout << num << endl;
			}
			else{
				primeTable(num, table);
				primeFact(num, table, fact);
				for(auto m : fact)
					cout << m.first << " ^ " << m.second << endl;
			}
			break;
	};

	return 0;
}
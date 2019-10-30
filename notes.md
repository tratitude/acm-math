# 程式競賽-數論
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef unsigned long long int ulld;
typedef pair<int, int> pii;
```
## 快速乘＆次方
```cpp
/*
Note: only for non-negative number
Complexity: O(log(min(a,b)))
Input: a, b
Output: a*b
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
Input: a, b
Output: a^b
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
```

## 質數
### 判斷質數
```cpp
/*
Complexity: O(sqrt(n))
Input: num
Output: true for num is prime
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
```
### 質數表
```cpp
/*
Complexity: O(sqrt(n))
Input: num, table store primes which not bigger than num
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
```
### 質因數分解
```cpp
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
```
## gcd&lcm
### theorem
- a*b = gcd(a,b) * lcm(a,b)
### 延伸
- lcm(S/a, S/b) = S/gcd(a, b)
### gcd&lcm
```cpp
lld gcd(lld a, lld b)
{
    lld max = a > b ? a : b;
    lld min = max == a ? b : a;
    while(min){
        lld tmp = min;
        min = max % tmp;
        max = tmp;
    }
    return max;
}

lld lcm(lld a, lld b)
{
    return a / gcd(a, b) * b;
}
```
## 擴展歐幾里得演算法
### theorem
- given a and b, ax+by = gcd(a, b) has solution
```cpp
/*
Link: https://tinyurl.com/y4b63knz
Note: given a and b, ax+by = gcd(a, b) has solution
      assume that a>=b
Input: a, b, x, y, gcd
*/
void extend_Eulid(lld a, lld b, lld &x, lld &y, lld &gcd)
{
	if (!b){
		gcd = a, x = 1, y = 0;
	}
	else{
		extend_Eulid(b, a % b, y, x, gcd);
		y -= x * (a / b);
	}
}
```
## 餘數相關定理
### 威爾遜定理
### 費馬小定理
### 歐拉定理
### 廣義歐拉定理
### 中國剩餘定理
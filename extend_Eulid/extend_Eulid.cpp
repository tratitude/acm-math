#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
	lld a, b, x, y, gcd; cin >> a >> b;

	extend_Eulid(a, b, x, y, gcd);

	if(a*x+b*y == gcd){
		cout << "correct\n";
	}
	else{
		cout << "wrong\n";
	}
	cout << a << " * " << x << " + " << b << " * " << y << " = " << gcd << endl;

	return 0;
}
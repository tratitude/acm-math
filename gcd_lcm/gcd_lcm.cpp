#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;

/*
Relation of gcd and lcm: a*b = gcd(a,b) * lcm(a,b)
*/

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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
    lld a,b;
    while(cin >> a >> b){
        cout << a << " " << b << " gcd: " << gcd(a,b) << endl;
        cout << a << " " << b << " lcm: " << lcm(a,b) << endl;
    }

	return 0;
}
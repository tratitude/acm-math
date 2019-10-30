/*
Link: https://en.wikipedia.org/wiki/Chinese_remainder_theorem
Input:
    k: as number of equations
    mouli: pairwise coprime
    intnum: any integers
*/
#include "../template.hpp"

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	
    int k; cin >> k;
    vector<lld> moduli;
    vector<lld> intnum;
    lld M = 1;
    lld total = 0;

    for(int i=0; i<k; i++){
        lld a, n; cin >> a >> n;
        moduli.push_back(n);
        intnum.push_back(a);
        M *= n;
    }

    for(int i=0; i<k; i++){
        int mul = 1;
        int num = M / moduli[i];
        while((num * mul)%moduli[i] != 1){ ++mul; }
        total += num * mul * intnum[i];
    }
    cout << "x = " << total << " + K * " << M << endl;

	return 0;
}
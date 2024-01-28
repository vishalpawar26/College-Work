#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
	    int n;
	    cin >> n;
	    string s, t, u;
	    cin >> s >> t >> u;
	    if (s == t) {
	        cout << u << endl;
	        continue;
	    }
	    else if (s == u) {
	        cout << t << endl;
	        continue;
	    }
        int k = abs((t[0] - 'a') - (s[0] - 'a'));
        cout << k << " ";
	    if (k > 13) k -= 26; 
	    for (int i = 0; i < n; i++) {
	        u[i] += k;
	        if (u[i] < 97)
	            u[i] = ('z' - ('a' - u[i])) + 1;
	    }
	    cout << u << endl;
	}
	return 0;
}

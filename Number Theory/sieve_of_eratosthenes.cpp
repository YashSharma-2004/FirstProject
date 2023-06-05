
#include<bits/stdc++.h>

using namespace std;
// declare globally if constraints are 10^7 if type of int
bool arr[1000001]; // declare globally if constraints are 10^8 

int isPrime(int n) {
    
    for(int i = 2; i <= n; i++) {
        arr[i] = 1;
    }
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(arr[i]) {
            cnt++;

            for (int j = 2 * i; j < n; j+=i) {
                arr[j] = 0;
            }
        }
    }
    return cnt;

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << isPrime(n) << endl;
    }
}
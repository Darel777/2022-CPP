#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int key;
    cin >> key;
    cout << abs(( long long int)(3 * pow(key,3) + 5 * pow(key,2) + 7 * key + 11)) % 4;
}
//2->1 6->1 10->1
//1->2 3->2 5->2 7->2 9->2
//4->3 8->3
#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
	char id; 
	int dead; 
	int profit; 
};
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, comparison);

	int result[n]; 
	bool slot[n]; 


	for (int i = 0; i < n; i++)
		slot[i] = false;
	for (int i = 0; i < n; i++) {

		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {

			if (slot[j] == false) {
				result[j] = i; 
				slot[j] = true; 
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";
	printJobScheduling(arr, n);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Customer{
    int s,f,comp;
};
bool cmp(Customer a,Customer b){
    if(a.comp == b.comp) return a.f < b.f;
    return a.comp < b.comp;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Customer arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].s;
            cin>>arr[i].f;
            cin>>arr[i].comp;
        }
        sort(arr,arr+n,cmp);
        int count = (n>0) ? 1:0;
        int i=0;
        for(int j=1;j<n;j++){
            if(arr[j].comp!=arr[i].comp)
            {
                count++;
                i=j;
            }
            else if(arr[j].s>=arr[i].f)
            {
                count++;
                i=j;
            }
        }
        cout<<count<<endl;
    }
return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int> nums;
long long merge(int left, int mid, int right) 
{
    int i = left, j = mid + 1, k = 0;
    vector<int> temp(right - left + 1);
    long long count = 0;
    while (i <= mid && j <= right) 
    {
        if (nums[i] <= nums[j]) 
        {
            temp[k++] = nums[i++];
        }
        else 
        {
            temp[k++] = nums[j++];
            count = count + mid - i + 1;
        }
    }
    while (i <= mid) 
    {
        temp[k++] = nums[i++];
    }
    while (j <= right) 
    {
        temp[k++] = nums[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++) 
    {
        nums[i] = temp[k];
    }
    return count;
}

long long mergeSort(int left, int right) 
{
    if (left >= right) 
    {  
        return 0;
    }
    int mid = (left + right) / 2;
    long long count = mergeSort(left, mid) + mergeSort(mid + 1, right);
    count = count + merge(left, mid, right);
    return count;
}

int main() 
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    long long count = mergeSort(0, nums.size() - 1);
    cout << count << endl;
    return 0;
}

//REVERSING AN ARRAY

#include <iostream>
using namespace std;
int main() {
    int arr[50];
    int n;
    int i;
    cout<<"enter the no of elementrs in array"<<endl;
    cin>>n;
    cout<<"the elements are";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k=0;
    int j=n-1;
    while(k<j)
    {
        int temp;
        temp=arr[k];
        arr[k]=arr[j];
        arr[j]=temp;
        k++;
        j--;
    }
    cout<<"reversed array is"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    

    return 0;
}

// **lARGEST ELEMENT or SMALLEST ELEMENT**
//brute force,sort the array and return the last element: O(NLOGN)
//optimal sol: O(N)

l=arr[0] //LARGEST
for(int i=1;i<n;i++)
{
	if(arr[i]>l)
	{
		l=arr[i]
	}
}

//	SECOND LARGEST
//brute force: sort+traverse from back second last element,if it is not equal to largest,return
//o(nlogn+n)

l=arr[n-1];
for(int i=n-2;i>=0;i--)
{
	if(arr[i]!=l)
	{
		sl= arr[i];
		break;
	}
}
// Better approach: o(2n)
// find largest element as above
//sl will be sl if it is smaller than largest but larger than rest
sl=-99999 
for(int i=0;i<n;i++)
{
	if (arr[i]>sl && arr[i]!=l)
	{
		sl=arr[i]
	}
}
//optimal approach: o(n)
l=arr[0]
sl=-99999
for(int i=1;i<n;i++)
{
	if(arr[i]>l)
	{
		sl=l
		l=arr[i]
	}
	else if(arr[i<l&&arr[i]>sl])
	{
		sl=arr[i]
	}
}
//similarly for second smallest take,ss as 100000000(some max value)

//AN ARRAY SORTED OR NOT
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i-1] > arr[i]) {
            return false;
        }
    }
    return true;
}

//REMOVE DUPLICATES FROM SORTED ARRAY:
#include <iostream>
using namespace std;

int main() {
    int arr[50];
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int writeIndex = 1; // Index to write the next unique element

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    // Output the array after removing duplicates
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < writeIndex; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}

//ROTATE AN ARRAY TO LEFT BY ONE PLACE: O(N)

temp=arr[0]
for(int i=1;i<n;i++)
{
	arr[i-1]=arr[i];
}
arr[n-1]=temp;

//ROTATE AN ARRAY TO LEFT BY k PLACES:
//if no of elemnts are k and k times rotated,get back t og array,any multiple of n will give same result
//brute: O(N+K) with extra space O(k)

#include <iostream>
using namespace std;
int main() {
    int arr[50];
    int n;
    int i;
    int k;
    cout<<"enter the no of elementrs in array"<<endl;
    cin>>n;
    cout<<"the elements are";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
cout<<"enter value of k"<<endl;
cin>>k;
int temp[50]; //O(K)
for(int i=0;i<k;i++)
{
    temp[i]=arr[i];
}
int ind=0; //O(N-K)
for(int i=k;i<n;i++)
{
    arr[ind]=arr[i];
    ind++;
}
int j=0;
for(int i=n-k;i<n;i++) //O(K)
{
    arr[i]=temp[j];
    j++;
}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<"\t";
}
}
//optimal solution:reverse the array upto k places,now reverse the remqining array,now reverse the entire array
// TIME-O(2N),O(1)-SPACE

#include <iostream>
using namespace std;
void reverse(int arr[50],int s,int e)
{
    while(s<=e)
    {
        int temp;
        temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
        s++;
        e--;
    }
    
}
int main() {
    int arr[50];
    int n;
    int i;
    int k;
    cout<<"enter the no of elementrs in array"<<endl;
    cin>>n;
    cout<<"the elements are";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the value of k"<<endl;
    cin>>k;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    cout<<"reversed array is"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}

// MOVE ALL ZEROES TO END OF ARRAY

int low=0; //maintain order od 0s
int high=n-1;  //order of 2s
int mid=0;//order of 1s,if 0s and 2s are sorted,1s will be sorted automatically
while(mid<=high)
{
    if(arr1[mid]==0)
    {
        int temp;
        temp=arr1[mid];
        arr1[mid]=arr1[high];
        arr1[high]=temp;
        high--;
    }
    else
    {
        mid++;
    }
}

//UNION OF  TWO SORTED ARRAYS: O(N1+N2)

#include <bits/stdc++.h>
using namespace std;

vector <int> sortedArray(vector <int> a, vector <int> b) {
    int n1 = a.size();
    int n2 = b.size();
    vector <int> unionarr;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (unionarr.size() == 0 || unionarr.back() != a[i]) {
                unionarr.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            if (unionarr.size() == 0 || unionarr.back() != b[j]) {
                unionarr.push_back(b[j]);
            }
            j++;
        } else {
            if (unionarr.size() == 0 || unionarr.back() != a[i]) {
                unionarr.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n1) {
        if (unionarr.size() == 0 || unionarr.back() != a[i]) {
            unionarr.push_back(a[i]);
        }
        i++;
    }

    while (j < n2) {
        if (unionarr.size() == 0 || unionarr.back() != b[j]) {
            unionarr.push_back(b[j]);
        }
        j++;
    }

    return unionarr;
}


//INTERSECTION OF TWO SORTED ARRAYS: O(N1+N2) BUT NO EXTRA SPACE
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector <int> interarr;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i]<arr2[j]) {
			i++;
          
        }
		else if(arr1[i]>arr2[j])
		{
			j++;
		}
		else{
			interarr.push_back(arr1[i]);
			i++;
			j++;
		}
    }

    return interarr;
}

//MISSING NUMBER:
//brute force :(n^2)
int missingNumber(vector<int>&a, int N) {
    int flag;
    for(int i=1;i<N;i++)
    {
        flag=0;
        for (int j = 0; j < N - 1; j++) {
          if (a[j] == i)
          {
            flag = 1;
            break;
          }
            
        }
        if(flag==0)
    {
        return i;
    }
    }
    
}

//BETTER:using hashing :	O(2N),SPACE: O(N)
#include <vector>
int missingNumber(std::vector<int>& a, int N) {
    vector<int> b(N+1, 0);

    for(int j = 0; j < N; j++) {
        if (a[j] <= N) {
            b[a[j]] = 1;
        }
    }
    for(int k = 1; k <= N; k++) {
        if(b[k] == 0) {
            return k;
        }
    }

    // This return is just a fallback; the logic guarantees it will return within the loop
    return -1;
}

//OPTIMAL: o(n),o(1)
#include <iostream>
using namespace std;
int main() {
int arr[50];
int n;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int sum=n*(n+1)/2;
int add=0;
for(int i=0;i<n;i++)
{
    add=add+arr[i];
}
cout<<"the missing number is"<<sum-add<<endl;
    return 0;
}

//XOR METHOD:
int missingNumber(vector<int>&a, int N) {
    vector <int> b;
    int m1=0;
    int m2=0;
    for (int i = 1; i <= N; i++) 
    {
      m1 = m1 ^ i;
    }

    for(int j=0;j<N-1;j++)
    {
        m2=m2^a[j];
    }
    int ans=m1^m2;    
    return ans;
}

//MAX CONSECUTIVE ONES:
int consecutiveOnes(vector<int>& arr){
    int count=0;
    int n=arr.size();
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            if(count>max)
            {
                max=count;
            }
        } 
        else {
            count = 0;
            continue;
        }
   
    }
      return max;
}

//FIND ELEMENT THAT APPEARS ONLY ONCE:
#include <vector>

int getSingleElement(std::vector<int> &arr) {
    int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        result ^= arr[i];
    }
    return result;
}

//LONGEST SUBARRAY HAVINF SUM K:
//brute: o(n2)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int sum;
    int l=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum=sum+a[j];
     
            if(sum==k)
        {
            l=max(l,j-i+1);
        }
        }
        
    }
    return l;
    
}

// better appraoch:hashmap 
//most optimal sol if array has both + and -numbers
 /*here we are using maps,it stores values like <sum,index>
   we will traverse the enitre array from starting and check if sum equals to k
   if sum==k,we will store maxlen:max(maxlen,i+1)
   We calculate the remainder rem as s - k. This represents the sum
   that we want,the subarray from the next index of rem to the current
    index  will give  sum k,again select maxlen
   also,consider situation where positives and negatives ,or 0s are present in the array
   */
#include <map>
int longestSubarrayWithSumK(vector<int> a, long long k) {
   map <long long , int> premap1;
   long long s=0;
   int l=0;
   for(int i=0;i<a.size();i++)
   {
      s=s+a[i];
      if(s==k)
      {
         l=max(l,i+1);
      }
      long long rem=s-k;
      if(premap1.find(rem)!=premap1.end())
      {
         int len=i-premap1[rem];
         l=max(l,len);
      }
      if(premap1.find(s)==premap1.end())
      {
         premap1[s]=i; /*If s is already a key in the map premap1, 
		 it updates the value associated with that key to i.
		 If s is not a key in the map, it inserts a new key-value pair
		  into the map with s as the key and i as the value. */
      }
   }
   return l;
        
}

//array with 0,+: most optimal sol

#include <map>
int longestSubarrayWithSumK(vector<int> a, long long k) {
   int left=0;
   int right=0;
   long long s=a[0];
   int l=0;
   int n=a.size();
   while(right<n)
   {
      while(left<=right && s>k)
      {
         s=s-a[left];
         left++;
      }
      
      if(s==k)
      {
         l=max(l,right-left+1);
      }
      /*if sum!=k*/
      right++;
      if(right<n)
      {
         s=s+a[right];
      }
   }

   
   return l;
        
}

//TWO SUM: ANY 2 NUMBERS GIVING THE TARGET SUM OR NOT
//brute
string read(int n, vector<int> book, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (book[i] + book[j] == target)
            {
                return "YES";
            }
        }
    }
    return "NO";
}

//HASHING
o(nlogn),o(n2)
#include<map>
string read(int n, vector<int> book, int target)
{
    // HASHING
    int rem;
    map <int , int> mpp;
    for(int i=0;i<n;i++)
    {
      rem=target-book[i];
      if(mpp.find(rem)!=mpp.end())
      {
          return "YES";
      }
      mpp[book[i]]=i;
    }
  return "NO";
}

//best optimal
string read(int n, vector<int> book, int target)
{
    int l=0;
    int r=n-1;
    int sum1=0;
    sort(book.begin(),book.end());
    while(l<=r)
    {
        sum1=book[l]+book[r];
        if(sum1==target)
        {
            return "YES";
        }
        else if(sum1<target)
        l++;
        else
        r--;
    }
    return "NO";
}

//MAJORITY ELEMENT:APPEARING MORE THAN N/2 TIMESS
//brute

int majorityElement(vector<int> v) {
	int n=v.size();
	int m=n/2;
	for(int i=0;i<n;i++)
	{
		int count=0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j])
			{
				count++;
			}
        }
		if(count>m)
		{
			return v[i];
		}
            
	}
	return -1;
}
//hashing o(nlogn)+o(n),o(n)-map space
#include <map>
int majorityElement(vector<int> v) {
    map <int, int> mpp;
	int n=v.size();
	int m=n/2;
	for(int i=0;i<n;i++)
	{
		mpp[v[i]]++; //mpp[v[i]] accesses the value in the map corresponding to the key v[i]. If v[i] is not already a key in mpp, a new entry is created with the default 
		//value of the map's value type (typically 0 for integers).operator increments the value associated with the key v[i] by 1. This effectively counts the occurrences of
	     //each element in the vector v.                
	}
	for(auto it: mpp)
	{
		if(it.second>m)
		{
			return it.first;
		}
	}
	return -1;
}

//optimal:	// MOORE'S VOTING ALGO:
int majorityElement(vector<int> v) {

	// any elmnt appearing more than n/2 times will not be cancelled
	//the one that dominates will be the ans
	int c=0;
	int el;
	for(int i=0;i<v.size();i++) // First pass: Find a potential candidate for majority element
	{
		if(c==0) //new section has started
		{
			c=1;
			el=v[i];

		}
		else if(v[i]==el)
		{
			c++;
		}
		else{
			c--;
		}
	}
	int c1=0;   // Second pass: Verify if the candidate is actually the majority element
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==el)
		c1++;
	}
	if(c1>v.size()/2) // Check if the candidate element count is greater than half of the array size
	{
		return el;
	}
return -1;
}

// MAXIMUM SUBARRAY SUM: KADANE'S ALGO:
//brute: o(n3)
long long maxSubarraySum(vector<int> arr, int n)
{
    int sum1;
    int max1=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum1=0;
            for(int k=i;k<=j;k++)
            {
              sum1=sum1+arr[k];
            }
        max1=max(max1,sum1);
        }
    }
    return max1;
}

//better

long long maxSubarraySum(vector<int> arr, int n)
{
    int sum1;
    int max1=0;
    for(int i=0;i<n;i++)
    {  
      sum1=0;
      for (int j = i; j < n; j++) {
        sum1 = sum1 + arr[j];
        max1=max(max1,sum1);
      }
        
    }
    return max1;
}

//optimal 
#include <vector>
#include <climits>

long long maxSubarraySum(std::vector<int> arr, int n)
{
    long long sum1 = 0;
    long long max1 = LLONG_MIN;  // Use LLONG_MIN for long long type
    int s = 0;
    int count=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        count++;
    }
    if(count==n)
    {
        max1=0;
    }

    for (int i = 0; i < n; i++)
    {
        if (sum1 == 0)
        {
            s = i;
        }

        sum1 += arr[i];

        if (sum1 > max1)
        {
            max1 = sum1;
            
        }

        if (sum1 < 0)
        {
            sum1 = 0;
        }
    }

    return max1;
}

//ALTERNATE POSITIVE NEGATIVE ELELMENTS PLACEMENT:
//brute

vector<int> alternateNumbers(vector<int>&a) {
 int n= a.size();
 vector <int> pos;
 vector <int> neg;
 vector <int> fin;
 int k=0;
 for(int i=0;i<n;i++)
 {
     if(a[i]<0)
     {
        neg.push_back(a[i]);
     }
     else
     pos.push_back(a[i]);
 }
 int posindex=0;
 int negindex=0;
 for(int j=0;j<n;j++)
 {
     if(j%2==0)
     {
       if(posindex<pos.size())
       fin.push_back(pos[posindex++]);

     }
     else
     if(negindex<neg.size())
     {
        fin.push_back(neg[negindex++]);

     }
      
     
 }
 return fin;
}

//optimal:

#include <vector>
using namespace std;
vector<int> alternateNumbers(vector<int>& a) {
    int n = a.size();
    int posindex = 0;
    int negindex = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            if (negindex < n)
            
             {
                ans[negindex] = a[i];
                negindex += 2;
            }
        } 
        else {
            if (posindex < n)
             {
                ans[posindex] = a[i];
                posindex += 2;
            }
        }
    }

    return ans;
}


//vareity 2: when some positives or negatives are extraaa

#include <vector>
using namespace std;
vector<int> alternateNumbers(vector<int>& a) {
    int n = a.size();
    int posindex = 0;
    int negindex = 1;
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            if (negindex < n) {
                ans[negindex] = a[i];
                negindex += 2;
            }
        } else {
            if (posindex < n) {
                ans[posindex] = a[i];
                posindex += 2;
            }
        }
    }
    while (posindex < n && !a.empty()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 0) {
                ans[posindex] = a[i];
                posindex += 2;
            }
        }
    }

    while (negindex < n && !a.empty()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                ans[negindex] = a[i];
                negindex += 2;
            }
        }
    }

    return ans;
}

// BUY AND SELL PROBELM:
/*You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes.
 Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.
You can’t sell without buying first.*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0; // Handle case where there are less than 2 prices.

    int mini = prices[0];
    int max1 = 0; // Initial max profit should be 0.

    for (int i = 1; i < n; i++) {
        // Update the minimum price
        if (prices[i] < mini) {
            mini = prices[i];
        } else {
            // Calculate potential profit and update max1
            int p = prices[i] - mini;
            max1 = max(max1, p);
        }
    }

    return max1;
}

// You are given an array ‘a’ of ‘n’ integers.You have to return the lexicographically next to greater permutation.If such a sequence is impossible, it must be rearranged
// in the lowest possible order.
/*Input: 'a' = [1, 3, 2]
Output: 2 1 3
Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of 
[1, 3, 2] is [2, 1, 3].*/


vector<int> nextGreaterPermutation(vector<int> &A) {
   //our break point will be where a[i]<a[i+1],so that we get permuation with next greater value
   //now select element that is greater than a[i] but lowest greater
   //place reamining in sorted order

   int ind=-1;
   int n= A.size();
   for(int i=n-2;i>=0;i--)
   {
       if(A[i]<A[i+1])
       {
           ind=i;
           break;
       }
   }
   if (ind == -1) /*If ind remains -1, it means the vector is sorted in descending order, 
                   and no higher permutation is possible.In this case, the function reverses
                   vector to return the lowest possible permutation (sorted in ascending order).*/
   {
       reverse(A.begin(),A.end());
       return A;
   }

   for(int i=n-1;i>=0;i--) /*t finds the smallest element greater than A[ind] from the right
   of the array.Once found, it swaps A[i] and A[ind]. This ensures that the new permutation
    is the next higher one.*/

   {
       if(A[i]>A[ind])
       {
           swap(A[i],A[ind]);
           break;
       }
   }

   reverse(A.begin()+ind+1,A.end());
   //The elements to the right of ind are reversed to get the smallest possible order for 
   //this part.This ensures that the new permutation is the smallest possible permutation
   // that is larger than the current one.
   return A;
}

//An element is called a Superior Element if it is greater than all the elements present to its right.You must return an array all Superior Elements in the array ‘a’.

#include <vector>
#include <algorithm>
using namespace std;

vector<int> superiorElements(vector<int>& a) {
    vector<int> ans;
    int n = a.size();
    
    if (n == 0) {
        return ans;  // Return empty vector if input is empty
    }
    
    // Traverse from the end to find superior elements
    int max_from_right = a[n-1];
    ans.push_back(max_from_right);
    
    for (int i = n-2; i >= 0; --i) {
        if (a[i] > max_from_right) {
            max_from_right = a[i];
            ans.push_back(a[i]);
        }
    }
    
    // The result needs to be in sorted order
    sort(ans.begin(), ans.end());
    
    return ans;
}

// There is an integer array ‘A’ of size ‘N’.Sequence is successive when the adjacent elements of the sequence have a difference of 1.You must return the length of the 
//longest successive sequence.

int longestSuccessiveElements(vector<int>&a) {
    int n=a.size();
    int l=0;
    if(n==0) return 0;
    unordered_set <int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]); //all elements inserted in set
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        //checks if it - 1 is not in the set, indicating that it could be the start of a new consecutive sequence.
        {
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x=x+1;
                cnt++;
            }
            l=max(l,cnt);
        }
    }
    return l;
}

//You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or
// jth column of the matrix is 0.
1) The number of rows should be at least 1.

2) The number of columns should be at least 1.

#include <bits/stdc++.h> 
void markrow(vector<vector<int>> &matrix,int i, int m)
{
   for(int j=0;j<m;j++)
   {
	   if(matrix[i][j]!=0)
	   {
		   matrix[i][j]=-1;
	   }
   }
}
void markcol(vector<vector<int>> &matrix,int j, int n)
{
   for(int k=0;k<n;k++)
   {
	   if(matrix[k][j]!=0)
	   {
		   matrix[k][j]=-1;
	   }
   }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				markrow(matrix,i,m);
				markcol(matrix,j,n);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==-1)
			{
				matrix[i][j]=0;
			}
		}
	}

	return matrix;
}

//OPTIMAL
/*we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try to use the 1st row
 and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row
  of the matrix will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array.
If any cell in the 0th row contains 0, we will mark matrix[0][0] as 0 and if any cell in the 0th column contains 0, we will mark the col0 variable as 0.*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

//ROTATE AATRIX BY 90 DEGREE:
//take transpose and reverse each row
#include<vector>
#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

	
// SPIRAL MOVEMENT IN A MATRIX:
vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    int n=MATRIX.size();
    int m=MATRIX[0].size();
    int r=m-1;
    int l=0;
    int b=n-1;
    int t=0;
    vector <int> ans;
    //right
    while(t<=b&&l<=r)
    {
        for(int i=l;i<=r;i++)
    {
        ans.push_back(MATRIX[t][i]);

    }
    t++;
    //bottom
    for(int i=t;i<=b;i++)
    {
        ans.push_back(MATRIX[i][r]);

    }
    r--;
    //left
    if(t<=b)
    {
    for(int i=r;i>=l;i--)
    {
        ans.push_back(MATRIX[b][i]);

    }
      b--;
    }
    
    //top
    if(l<=r)
    {
       for(int i=b;i>=t;i--)
    {
        ans.push_back(MATRIX[i][l]);

    }
    l++;
    }
   

    }
    
    return ans;


}

//NUMBER OF SUBARRAYS GIVING SUM K:
//mpp[0] = 1;: This initializes the map with 0 as a key and 1 as its value. This accounts for the case where a prefix sum itself equals k.
//JITNI BAAR HUME MP MEIN (X-K) MILEGA,UTNE SUBARRAYS SUM K DERE HONGE


#include <bits/stdc++.h>
using namespace std;
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    map <int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}


//PASCAL TRIANGLE:
//VARIATION 1: R AND C GIVEN,RETRUN ELELMNT AT THAT INDEX OF P.T:

//FORMULA: (R-1)C (c-1) 

#include <bits/stdc++.h>
using namespace std;

int nCr(int r, int c) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < c; i++) {
        res = res * (r- i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

//VARIATION 2: Given the row number n. Print the n-th row of Pascal’s triangle.

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

//VARIATION 3: PRINT PASCAL TRIANGLE FOR GIVEN VALUE OF N-NO OF ROWS
// i heree stands for col,jitne col h humare utni rowi hongi,6th row will hve 6 cols
//N is rows

#include <bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

//MAJORITY ELLEMNT : N/3 TIMES
//brute :o(n2)
#include<cmath>
vector<int> majorityElement(vector<int> v) {
	int n=v.size();
	int m= floor(n/3);
	vector <int>p;
	for(int i=0;i<n;i++)
	{
		int count=0;
        for (int j = i; j < n; j++) {
            if (v[i] == v[j])
			{
				count++;
			}
        }
		if(count>m)
		{
                        if (find(p.begin(), p.end(), v[i]) == p.end()) {
                                p.push_back(v[i]);
                        }
        }
            
	}
	return p;
}
//better

#include <map>
#include<cmath>
vector<int> majorityElement(vector<int> v) {
    map <int, int> mpp;
	vector <int> res;
	int n=v.size();
	int m= floor(n/3);
	for(int i=0;i<n;i++)
	{
		mpp[v[i]]++; //mpp[v[i]] accesses the value in the map corresponding to the key v[i]. If v[i] is not already a key in mpp, a new entry is created with the default 
		//value of the map's value type (typically 0 for integers).operator increments the value associated with the key v[i] by 1. This effectively counts the occurrences of
	     //each element in the vector v.                
	}
	for(auto it: mpp)
	{
		if(it.second>m)
		{
		 
            res.push_back(it.first);
    
		}
	}
	return res;
}

//optimal
 #include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

// THREE SUM:
//HASHING
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for(int i=0;i<n;i++)
    {
        set <int> t;
        for(int j=i+1;j<n;j++)
        {
         int third= -(arr[i]+arr[j]);
         if(t.find(third)!=t.end())
         {
             vector <int> temp= {arr[i],arr[j],third};
             sort(temp.begin(),temp.end());
             st.insert(temp);
         }
         t.insert(arr[j]);
        
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}
//optimal

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum == 0) {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);

                // Move the pointers to avoid duplicate triplets
                j++;
                k--;

                // Skip duplicate elements
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;

            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    return ans;
}

//4 SUM
//brute

#include <vector>
#include <set>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    set<vector<int>> seen;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end()); // Sort the quadruplet to maintain order
                        if (seen.find(temp) == seen.end()) {
                            seen.insert(temp);
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
    }
    
    return ans;
}

//better

#include<bits/stdc++.h>
vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
       
        for(int j=i+1;j<n;j++)
        {
             set <int> t;
            for(int k=j+1;k<n;k++)
            {
             long long fourth= target-(nums[i]+nums[j]+nums[k]);
             if(t.find(fourth)!=t.end())
             {
             vector <int> temp= {nums[i],nums[j],nums[k],fourth};
             sort(temp.begin(),temp.end());
             st.insert(temp);
             }
             t.insert(nums[k]);
            }       
        
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}

//optimal:


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 4) return ans;  // Early return if less than 4 numbers

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate elements for i

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i+1 && nums[j] == nums[j - 1]) continue;  // Skip duplicate elements for j
        /*The condition if (j > i+1 && nums[j] == nums[j - 1]) ensures
         that we skip duplicates for the second pointer j only
          after the first occurrence. This is analogous to how
           we skip duplicates for the first pointer i with the
            condition if (i > 0 && nums[i] == nums[i - 1]).*/
            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    
                    // Move the pointers to avoid duplicate triplets
                    while (k < l && nums[k] == nums[k + 1]) k++;
                    while (k < l && nums[l] == nums[l - 1]) l--;
                    k++;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    return ans;
}

// HOW MANY SUBARRAYS GIVE A TARGET AFTER XOR:
//brute

int subarraysWithSumK(vector<int> a, int b) {
    int n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = i; j < n; j++) {
            x ^= a[j];
            if (x == b) {
                count++;
            }
        }
    }

    return count;
}




















// WAP to find max or min element from array using minimum comparisons
#include <iostream>
using namespace std;
int getminmax(int arr[],int n)
{
    int min,max;
    if(n%2==0)//comparing pairwise iif even;
    {
        if(arr[0]>arr[1])
        {
            max=arr[0];
            min=arr[1];
            int i=2;
        }
        else
        {
            min=arr[0];
            max=arr[1]; 
        }
         int i=2;
    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
            if(arr[i+1]<min)
            {
                min=arr[i+1];
            }
        }
        else
        {
            if(arr[i]<arr[i+1])
            {
                if(arr[i+1]>max)
                max=arr[i+1];
                if(arr[i]<min)
                min=arr[i];
                
            }
        }
        i=i+2;
    }
    cout<<"maximum is"<<max<<endl;
    cout<<"minimum is"<<min;
}
        
    
    
    else
    {
        max=arr[0]; // if no of elements in an array are odd
        min=arr[0];
        int i=1;
    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
            if(arr[i+1]<min)
            {
                min=arr[i+1];
            }
        }
        else
        {
            if(arr[i]<arr[i+1])
            {
                if(arr[i+1]>max)
                max=arr[i+1];
                if(arr[i]<min)
                min=arr[i];
                
            }
        }
        i=i+1;
    }
    cout<<"maximum is"<<max<<endl;
    cout<<"minimum is"<<min;
    }
}
    //int i=2;
   

int main() {
int arr[50];
int n;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int t=getminmax(arr,n);


    return 0;
}

//WAP TO GET A MERGED SORTED ARRAY
#include <iostream>
using namespace std;
int main() {
int arr1[50];
int arr2[50];
int arr3[50];
int n1;
int n2;
int n3;

cout<<"enter no of elements"<<endl;
cin>>n1;
cout<<"the elements are"<<endl;
for(int i=0;i<n1;i++)
{
    cin>>arr1[i];
}
cout<<"enter no of elements of second array"<<endl;
cin>>n2;
cout<<"the elements are"<<endl;
for(int i=0;i<n2;i++)
{
    cin>>arr2[i];
}
n3=n1+n2;
int i=0;
int j=0;
int k=0;
while(i<n1&&j<n2)
{
    if(arr1[i]<arr2[j])
    {
        arr3[k++]=arr1[i++];
    }
    else
    {
        arr3[k++]=arr2[j++];
    }
}
while(i<n1)
{
    arr3[k++]=arr1[i++];
}
while(j<n2)
{
    arr3[k++]=arr2[j++];
}
cout<<"merged sorted array is"<<endl;
for(int m=0;m<n3;m++)
{
    cout<<arr3[m];
}
return 0;
}
 
 //WAP TO GET A  SORTED ARRAY of 0s,1s,2s
//bubble sort
#include <iostream>
using namespace std;
int main() {
int arr1[50];
int n;


cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr1[i];
}
for(int i=0;i<n-1;i++)//no of passes are (n-1)
{
    for(int j=0;j<n-i-1;j++)
    {
        if(arr1[j]>arr1[j+1])
    {
        int temp;
        temp=arr1[j];
        arr1[j]=arr1[j+1];
        arr1[j+1]=temp;
    }
    }
    
}
cout<<"sorted array is"<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr1[i]<<'\t';
}
return 0;
}
  
//SECOND APPROACH : BINARY SEARCH
 // Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
 int arr1[50];
 int n;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr1[i];
}
int low=0; //maintain order od 0s
int high=n-1;  //order of 2s
int mid=0;//order of 1s,if 0s and 2s are sorted,1s will be sorted automatically
while(mid<=high)
{
    if(arr1[mid]==0)
    {
        int temp;
        temp=arr1[mid];
        arr1[mid]=arr1[low];
        arr1[low]=temp;
        low++;
        mid++;
    }
    else if(arr1[mid]==2)
    {
         int temp;
        temp=arr1[mid];
        arr1[mid]=arr1[high];
        arr1[high]=temp;
        high--; //no mid++ as the number swapped might be 0
    }
    else
    {
        mid++;
    }
}
cout<<"sorted array is"<<endl;
for(int i=0;i<n;i++)
{
    cout<<arr1[i]<<'\t';
}
    return 0;
}

// WAP TO FIND IF AN ARRAY IS A SUBARRAY 
#include <iostream>
using namespace std;
int main() {
 int arr1[50];
 int n;
 int arr2[50];
 int n2;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr1[i];
}
cout<<"enter no of elements of subarray"<<endl;
cin>>n2;
cout<<"the elements are"<<endl;
for(int i=0;i<n2;i++)
{
    cin>>arr2[i];
}
int count=0;
for(int i=0;i<n2;i++)
{
    for(int j=0;j<n;j++)
    {
        if(arr1[j]==arr2[i])
        {
            count++;
        }
    }
}
if(count==n2)
{
    cout<<"it is a subarray "<<endl;
}
else
cout<<"it is not a subarray "<<endl;
    return 0;
}
// WAP TO find no of pairs giving a sum in array
#include <iostream>
using namespace std;
int main() {
 int arr1[50];
 int n;
int sum;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr1[i];
}
cout<<"enter the sum that needs to be checked"<<endl;
cin>>sum;
int count=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(arr1[i]+arr1[j]==sum)
        {
            count++;
        }
    }
}
cout<<"no of pairs are "<<count<<endl;
    return 0;
}



//WAP TO SORT POSITIVE AND NEGATIVE NUMBERS IN AN ARRAY
#include <iostream>
using namespace std;
int main() {
 int arr[50];
 int n;
cout<<"enter no of elements"<<endl;
cin>>n;
cout<<"the elements are"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int s=0;
int e=n-1;
while(s<e)
{
    if(arr[s]>=0)
    {
        s++;
    }
    else if(arr[s]<0)
    {
        if(arr[e]>=0)
        {
            int temp;
            temp=arr[e];
            arr[e]=arr[s];
            arr[s]=temp;
            s++;
            e--;
        }
        else
        {
            e--;
            if(arr[e]>=0){
             int temp;
            temp=arr[e];
            arr[e]=arr[s];
            arr[s]=temp;
            s++;
            e--;
            }
             
            
        }
    }
    
    }
     cout<<"sorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<'\t';
    }
    

    return 0;
}


   




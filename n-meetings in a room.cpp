//URL: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
//APPROACH: 
/*
sort the array with ending time, if the start of a meeting is after the end of prev meeting --> increase the count.
taking in account the start, the end, the position. so we create a custom ds to store the 3 info.
*/

#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

//creating a data structure having a start, an end, and size.
struct ds 
{
    int s;
    int e;
    int pos;
};

//custom made sort function using COMAPRATOR
static bool comparator(struct ds m1, ds m2){
    if(m1.e<m2.e) return true;
    else if(m1.e>m2.e) return false;
    else if(m1.e = m2.e){
        if(m1.pos<m2.pos)
            return true;
    }
    return false;
}

void maxMeetings(vector<int> start, vector<int> end, int n)
    {
        struct ds ob[n];

        //pushing data into the create data structure
        for(int i=0;i<n;i++){
            ob[i].s = start[i];
            ob[i].e = end[i];
            ob[i].pos = i+1; 
        }

        //sort the data structure on the basis of increasing order of ending time
        sort(ob,ob+n,comparator);
        
         vector<int>ans;

        //setting the initial limit to first meeting's ending time
        int limit = ob[0].e;
        ans.push_back(ob[0].pos);

        //checking if the start time of a meeting is after the ending time of a previous meeting 
        for(int i=1;i<n;i++){
            if(ob[i].s > limit){
                ans.push_back(ob[i].pos);
                limit = ob[i].e;
            }
        }
  
        cout<<"the meetings are: ";
        for(auto i:ans)
            cout<<i<<" ";
    }

int main()
{
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    int n = start.size();
    //int target = 2;
    //cout << " volume " << 
    maxMeetings(start,end,n);
    return 0;
}

 
//T.C: O(N) (traversing the array) + O(log N) (pushing data in custom ds) + O(N) (traversing the array again) --> O(N log N)
//S.C: O(N)
    

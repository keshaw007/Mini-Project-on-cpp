#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int m=num1.length(),n=num2.length(),i,j;
        string ans;
        int carry=0;
        for(i=m-1,j=n-1;i>=0&&j>=0;i--,j--)
        {
            int k=(num1[i]-'0')+(num2[j]-'0')+carry;
            ans.push_back((char)k%10+'0');
            carry=k/10;
        }
        for(;i>=0;i--)
        {
            int k=num1[i]-'0'+carry;
            ans.push_back((char)k%10+'0');
            carry=k/10;
        }
        for(;j>=0;j--)
        {
            int k=num2[j]-'0'+carry;
            ans.push_back((char)k%10+'0');
            carry=k/10;
        }
        if(carry!=0) ans.push_back((char)carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    while(true)
    {
        string num1,num2,ans;
        cout<<"Enter two number :- \n";
        cin>>num1>>num2;
        Solution ob;
        ans=ob.addStrings(num1,num2);
        cout<<ans<<"\n";
        cout<<"Press 1 for next input and any other key for exit :- ";
        int answer_output;
        cin>>answer_output;
        if(answer_output==1) continue;
        else break;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string add(string s1, string s2)
    {
        int i,j,carry=0;
        string ans;
        for(i=s1.length()-1,j=s2.length()-1;i>=0&&j>=0;i--,j--)
        {
            int a=(int)s1[i]-'0'+(int)s2[j]-'0'+carry;
            ans.push_back((char)a%10+48);
            carry=a/10;
        }
        for(;i>=0;i--)
        {
            int a=(int)s2[i]-'0'+carry;
            ans.push_back((char)a%10+48);
            carry=a/10;
        }
        for(;j>=0;j--)
        {
            int a=(int)s2[j]-'0'+carry;
            ans.push_back((char)(a%10)+48);
            carry=a/10;
        }
        if(carry!=0)
        {
            ans.push_back((char)carry+48);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string multiply(string num1, string num2) 
    {
        int m=num1.length(),n=num2.length();
        int i,j;
        string ans;
        string aux2="";
        if(num1=="0" || num2=="0") return "0";
        for(i=n-1;i>=0;i--)
        {
            string aux1="";
            int carry=0;
            for(j=m-1;j>=0;j--)
            {
                int a=((int)num2[i]-'0')*((int)num1[j]-'0')+carry;
                aux1.push_back((char)(a%10)+48);
                carry=a/10;
            }
            if(carry!=0)
            {
                aux1.push_back((char)carry+48);
            }
            reverse(aux1.begin(),aux1.end());
            // aux2=aux2+aux1; call add function
            aux2=add(aux2,aux1);
            ans.push_back(aux2[aux2.length()-1]);
            aux2.pop_back();
        }
        for(int k=aux2.length()-1;k>=0;k--)
        {
            ans.push_back(aux2[k]);
        }
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
        ans=ob.multiply(num1,num2);
        cout<<ans<<"\n";
        cout<<"Press 1 for next input and any other key for exit :- ";
        int answer_output;
        cin>>answer_output;
        if(answer_output==1) continue;
        else break;
    }
    return 0;
}
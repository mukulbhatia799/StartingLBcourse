#include<iostream>
#include<vector>

using namespace std;


void solve(string& num1, string& num2, int ptr1, int ptr2, int carry, string& ans)
{   // always try to send the arguments in function using call by reference because the compiler will not make the copy in each iteration. Check the memory difference without call by refernence for num1 and num2 string.
        // base cond.
        if(ptr1 < 0 && ptr2 < 0) {  
            cout << "carry: " << carry << endl;
            if(carry > 0) ans.push_back(carry + '0');
            return ;
        }
        char ch1, ch2;
        if(ptr1 < 0) ch1 = '0';
        else if(ptr1 >= 0) ch1 = num1[ptr1];
        if(ptr2 < 0) ch2 = '0';
        else if(ptr2 >= 0) ch2 = num2[ptr2];
        int sum = int(ch1 - '0') + int(ch2 - '0') + carry;
        int summod = sum % 10;
        carry = sum / 10;
        // cout << "sum: " << sum << " carry: " << carry << endl;
        ans.push_back(char(summod) + '0');
        
        // recursive function
        solve(num1, num2, ptr1-1, ptr2-1, carry, ans);
}
string addStrings(string& num1, string& num2) {     // we can use call by reference to save the memory.         // Always try to send the arguments using call by reference specially during recursion and iterative approach.
        string ans;
        solve(num1, num2, num1.length()-1, num2.length()-1, 0, ans);
        // reverse the string
        // cout << "ans length: " << ans.length() << endl;
        for(int i = 0; i < ans.length()/2; i++)
        {
            swap(ans[i], ans[ans.length()-i-1]);
        }
        return ans;
}

int main(){
    string s1 = "123";
    string s2 = "967";

    addStrings(s1, s2);

    return 0;
}
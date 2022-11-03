class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     map<string,int>mp;    //  creating a map named mp, containing a string value present in words(given in Q.) and the count value as integer int, that shows the no.
                           //  no. of string present in words.
     int len = 0;          
     int ans = 0;           
     bool flag = false;      // it's for whether the case of equal char string is present or not i.e., cc, ll and so on. 
     for(auto word : words)    // storing the words value in word (using stl library)  
     {
         mp[word]++;           // counting the no. of word
     }
     for(auto x : mp)                     // map mp value is stored in x one by one and further implementing the code accordingly.
                                           //  mp = {(ab, 2), (ty,1), (yt,1), (gg,1)}. 
                                           //   here x is (ab,2)  and x.first= ab & x.second = 2
         
     {
         if(x.first[0] == x.first[1])     // checking whether the given string x have same char value or not, say for "aa" x.first[0] == x.first[1] == a. So, it's true.
         {
             if(x.second % 2 == 1)           // now, checking the no. of string present in words is odd or not, if yes then,
             {
                 flag = true;                 // set flag true
                 len+=(x.second-1);           // and the length will be equal to total length -1  that is {x.second-1}, bcz we have to make palindrome, so for that
                                              // we can only consider even no. of same char string, so we are substracting 1 from the total (odd) no.
             }
             else
             {
                 len+=mp[x.first];            // if it is even no. then no problem we can directly consider that no.
             }
              mp.erase(x.first);             // here after deciding the value we will erase those string or say x value from mp and move to next string.
         }
         else                                // now this case is for unequal char in string that is "ab", "yt" like this.
         {
             string str = x.first;                 // so first store that string in str
             reverse(str.begin(),str.end());        // then reverse the string and that will be stored in str now
             if(mp.find(str)!=mp.end())              // now check whether the reverse string str is present in mp or not (and if it is then that will be eq. to x.first())
             {
                 ans+=min(mp[str],x.second)*4;        // if the string is present then ans will be eq. to minimum value of total no. reverse string str and x, bcz we have
                                                      // to only consider the same no. then only we can make palindrome otherwise uneven no. of reverse string str and original
                                                      // string x will not form palindrome. eg: x.first = ab, x.second = 3, and str = ba and its count is 2; so for making 
                                                      // largest palindrome we will only consider 2 ab i.e., min. of ab and ba count. and palindrome will be "ababbaba"
             }
             mp.erase(str);                      // now after that erase both reverse string present in map as well as original one.
             mp.erase(x.first);
         }
     }
        if(flag)
         {
           return ans+len*2+2;  // now if flag is true that is odd case then return ans + length *2 (it is for there are two char in string, "aa" 2 a is there) + 2 (it is
                                // for the case when we have consider only even no. of string in odd case and we have substracted 1 from it, so we will consider them also here 
                                // bcz either we can take one of them or any another one i.e, if "cc" is total 3 and "gg" = 1 then two combination is possible either u take 3 cc
                                // or 2 cc and 1 gg. so total char in them is 2 i.e, 2 c or 2 g.
         }
         return ans+len*2;      // it is when flag is false that is even case so, directly return ans + length*2 (even no. of string is present)
    }
};

class Solution {
public:
    string tell(char s,char e)
    {
        string cur = "";
        if(s == e) return "!";
        if(s == 'z')
        {
            cur+="U";
            s = 'u';
        }
        int si = (s-'a'+1);
        int sj = (si)%5;
        if(sj == 0) sj = 5;
        si = (si+4)/5;

        int ti = (e-'a'+1);
        int tj = (ti)%5;
        if(tj == 0) tj = 5;
        ti = (ti+4)/5;

        if(sj<tj)
        {
            for(int i=1;i<=tj-sj;i++) cur+="R"; 
        }
        else
        {
            for(int i=1;i<=sj-tj;i++) cur+="L";
        }

        if(si<ti)
        {
            for(int i=1;i<=ti-si;i++) cur+="D";
        }
        else
        {
            for(int i=1;i<=si-ti;i++) cur+="U";
        }
        return cur+"!";
    }
    string alphabetBoardPath(string target) {
       char now = 'a';
       string ans = "";
       for(char ch:target)
       {
            ans+=(tell(now,ch));
            now = ch;
       }
       return ans;
    }
};
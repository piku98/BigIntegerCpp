#include<bits/stdc++.h>
using namespace std;
class BigInteger {
    public:
        string val;
        BigInteger(){
            val = "0";
        }
        BigInteger(string s) {
            val = s;
        }
        BigInteger operator + (BigInteger b) {
            BigInteger res;
            string operand = b.val;
            int vl = val.length();
            int bl = operand.length();
            string op1, op2;
            if (vl >= bl){
                op1 = val;
                op2 = operand;
            } else{
                op1 = operand;
                op2 = val;
            }
            int len = vl >= bl ? vl : bl;
            int j = vl <= bl ? vl - 1 : bl - 1;
            int carry = 0;
            res.val = "";
            for (int i = len - 1; i >= 0; i--) {
                int a = (int)op1[i] - 48;
                int b = j >= 0 ? (int)(op2[j] - 48) : 0;
                int r = a + b + carry;
                carry = r / 10;
                r = r % 10;
                char z = char(r + 48);
                res.val = z + res.val;
                j--;
            }
            return res;

        }
        BigInteger singleMul(char c, string s) {
            BigInteger result;
            result.val = "";
            int carry = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                int mul = (int)(s[i] - 48) * (int)(c - 48) + carry;
                carry = mul / 10;
                mul = mul % 10;
                result.val = (char)(mul + 48) + result.val;
            }
            return result;
        }
        BigInteger operator * (BigInteger b) {
            int vl = val.length();
            int bl = b.val.length();
            string op1, op2;
            if (vl <= bl) {
                op1 = val;
                op2 = b.val;
            } else {
                op1 = b.val;
                op2 = val;
            }
            BigInteger result = singleMul(op1[op1.length() - 1], op2);
            string m = "10";
            for (int i = op1.length() - 2; i >= 0; i--) {
                BigInteger temp = singleMul(op1[i], op2);
                temp.val = temp.val + "0";
                result = result + temp;
                
            }
            return result;
        }
        bool operator < (BigInteger b)  {
            int vl = val.length();
            int bl = b.val.length();
            if (vl < bl) {
                return true;
            } else if (vl > bl) {
                return false;
            } else  {
                for (int i = 0; i < vl; i++) {
                    if (val[i] > b.val[i])
                        return false;
                }
                return true;
            }
        }
        bool operator > (BigInteger b) {
            int vl = val.length();
            int bl = b.val.length();
            if (vl > bl) {
                return true;
            } else if (vl < bl) {
                return false;
            } else  {
                for (int i = 0; i < vl; i++) {
                    if (val[i] < b.val[i])
                        return false;
                }
                return true;
            }

        }
        bool operator <= (BigInteger b) {
            return *this > b ? false : true; 
        }
        bool operator >= (BigInteger b) {
            return *this < b ? false : true;
        }
};

int main(void) {
    BigInteger b1("456");
    BigInteger b2("2341");
    cout<<(b1<=b2);
}

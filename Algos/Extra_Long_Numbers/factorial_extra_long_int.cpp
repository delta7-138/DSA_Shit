#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> split_number(string num){
  vector <int>ans;
  for(int i = 0; i<num.length(); i+=4){
    string sub;
    for(int j = 0; j<4; j++){
      sub[j] = num[i + j];
    }
    ans.push_back(stoi(sub));
  }
  return ans;
}

string multiply(string num1 , string num2){

  vector <int>num_arr_1 = split_number(num1);
  vector <int>num_arr_2 = split_number(num2);

  //for(int i = 0; i<num_arr_1.size(); i++)
  //  cout<<num_arr_1[i]<<" ";

  vector <int>product;
  long sum = 0 , prod = 0, carry = 0;

  for(int i = num_arr_1.size()-1; i>=0; i--){
    for(int j = num_arr_2.size()-1; j>=0; j--){
      prod = num_arr_1[i] * num_arr_2[j];
      if(j==0 && i==0){
        sum = prod + carry;
      }
      else{
        sum = prod%10000 + carry;
        carry = prod/10000;
      }

      product.push_back(sum);
    }
  }
  vector <int>ans;
  for(int i = 0;  i<product.size(); i++){
    ans.push_back(product[product.size() - i - 1]);
  }
  return ans;
}

vector <int>factorial(long num){
  string ans = "1";
  for(int i = 1; i<=num; i++){
    string temp = to_string(i);
    ans = multiply(ans , temp);
  }
  return split_number(ans);
}

int main(){
  long num;
  cin>>num;

  vector <int>ans = factorial(num);
  for(int i = 0; i<ans.size(); i++){
    if(ans[i]/10==0){
      cout<<"000"<<ans[i];
    }else if(ans[i]/100==0){
      cout<<"00"<<ans[i];
    }else if(ans[i]/1000==0){
      cout<<"0"<<ans[i];
    }else{
      cout<<ans[i];
    }
  }
  cout<<endl;
}

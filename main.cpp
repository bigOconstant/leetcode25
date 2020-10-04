#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     ListNode* insert(int x){
           if(!next) {
               next = new ListNode(x);
               return next;
           } else{
             return next->insert(x);  
           }
     }
     
     void print() {
            cout<<val;
            if(next) {
                cout<<",";
                next->print();
            }
     }
  };
  
  ListNode* reverseKGroup(ListNode* head, int k) {
        
        std::vector<ListNode*> List;
        ListNode* itr = head;
        while (itr) {
                List.push_back(itr);
                itr = itr->next;
        }
        
        for(int i = 0; i < List.size(); i += k){
            if(i +k <= List.size()){
                    std::vector<ListNode*> reversek;
                    for(int j = i +k-1; j >= i; --j) {
                            reversek.push_back(List[j]);
                    }
                    int counter = k -1;
                    for(int j = i +k-1; j >= i; --j) {
                            List[j] = reversek[counter];
                            --counter;
                    }
            }
        }
         for(int i = 0; i < List.size(); ++i) {
             if(i < List.size()-1){
                    List[i]->next = List[i+1];
             }else{
                    List[i]->next = NULL;
             }
         }
        
        return List[0];
        
    }
int main(int argc, char **argv) {
    
    //1,2,3,4,5
    ListNode *root = new ListNode(1);
    root->insert(2)->insert(3)->insert(4)->insert(5);
    

    std::cout << std::endl;
    root = reverseKGroup(root,3);
    cout<<"printing"<<endl;
    root->print();
    cout<<endl;
    
    ListNode *small = new ListNode(1);
    small->insert(2);
    small = reverseKGroup(small,2);
    small->print();
    cout<<endl;
    return 0;
}

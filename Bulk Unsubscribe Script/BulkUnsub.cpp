

#include <iostream>
using namespace std;
 
int main () {
   int a = 1;

   while( a < 96 ) {
      
      // __________________________________________________________________________________________
      // Chrome
      
      //Header:
      // VERSION BUILD=844 RECORDER=CR
      // URL GOTO=https://www.youtube.com/subscription_manager
      
      // cout << "TAG POS=" << a << " TYPE=SPAN ATTR=TXT:Unsubscribe" << endl;
      // cout << "TAG POS=184 TYPE=SPAN ATTR=TXT:Unsubscribe" << endl;
      
      // __________________________________________________________________________________________
      // Firefox
      
      // Header:
      // VERSION BUILD=9030808 RECORDER=FX
      // TAB T=1
      // URL GOTO=https://www.youtube.com/subscription_manager

      // cout << "TAG POS=" << a << " TYPE=BUTTON ATTR=TXT:SubscribeSubscribedUnsubscribe" << endl;
      // cout << "TAG POS=90 TYPE=BUTTON ATTR=TXT:Unsubscribe" << endl;
      // __________________________________________________________________________________________
 
      a++;
   }
 
   return 0;
}

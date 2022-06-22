
#include "container/container.hpp"

#include "vector/vector.hpp"

#include "list/list.hpp"

#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */
#include <iostream>
using namespace std;
/* ************************************************************************** */

int main() {
  
  
  cout << "Lasd Libraries 2022" << endl;
  char scelta;
  cout <<"Vuoi eseguire myTest (1) o eseguire direttamente lasdTest (2)? ";
  cin >> scelta;
  if(scelta =='1')
    mytest();
  
  lasdtest();
  
  
  return 0;
}

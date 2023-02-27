#include<iostream>
#include<tuple>
#include<string>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
#include<map>

using namespace std;

// Definições e variáveis globais necessárias
typedef int element_t;                                                          // tipo do elemento
typedef vector<element_t> array_t;                                              // tipo do array
typedef tuple<int, int, double> loginfo_t;                                      // armazena informações de desempenho <trocas, comparações, tempo em ms>

void selectionsort(array_t&, loginfo_t&);
void heapsort(array_t&, loginfo_t&);
void buildheap(array_t&, loginfo_t&);
int filho_e(const array_t&, element_t);
int filho_d(const array_t&, element_t);
int pai(const array_t&, element_t);
void heapify(array_t&, element_t, int, loginfo_t&);
int heap_max(const array_t&, loginfo_t&);
int extract_max(array_t&, loginfo_t&);
void heap_insert(array_t&, element_t, loginfo_t&);
void swap(element_t* n1, element_t* n2);

int main(void){
  loginfo_t loginfo;
  int qtd;
  array_t array1 = {1,2,3,4,5,6,7,8};

  buildheap(array1, loginfo);
  
  for(auto e:array1)
     cout << e << " ";  
  cout << endl;

  array_t array2 = {9,8,7,6,5,4,3,1};
  heapsort(array2, loginfo);

  for(auto e:array2)
     cout << e << " ";  
  cout << endl;

  return 0;
}

// ################################################
// Algoritmos de ordenação por Seleção
// ################################################
 
// Seleção direta 
void selectionsort(array_t& array, loginfo_t& loginfo){
   int trocas = 0;
   int comparacoes = 0;
   element_t menorchave;
   int qtd_elementos = array.size()-1;  

   for(auto i=0; i<qtd_elementos;i++){
      menorchave = i;
      for(auto j=i; j<qtd_elementos+1; j++){                   
         comparacoes = comparacoes + 1;
         if(array[j] < array[menorchave]){ 
            menorchave = j;
         }
      }   
      if(menorchave != i){
         swap(array[i], array[menorchave]);
         trocas = trocas + 1;
      }
   }
   get<0>(loginfo)=trocas;
   get<1>(loginfo)=comparacoes;
} 

// Heapsort e funções auxiliares
void heapsort(array_t& array, loginfo_t& loginfo){
   int trocas = 0;
   int comparacoes = 0;
   int heap_size = array.size();
   int qtd_elementos = heap_size-1;   
    
   buildheap(array, loginfo);
    
   for(auto i = qtd_elementos; i>0; i--){
      trocas++;
      swap(array[i], array[0]);
      heap_size--;
      heapify(array, 0, heap_size, loginfo); 
   }
   get<0>(loginfo)=trocas;
   get<1>(loginfo)=comparacoes;
}

// usada no heapsort
void buildheap(array_t& array, loginfo_t& loginfo){
   int ultimo_pai = (array.size()/2)-1;
   for(auto i=ultimo_pai; i>=0; i--)
      heapify(array, i, array.size(), loginfo);
}
  
int filho_e(const array_t& array, element_t elemento){
   return elemento*2+1;
}
 
int filho_d(const array_t& array, element_t elemento){
   return elemento*2+2;
}
 
int pai(const array_t& array, element_t elemento){
   return (elemento/2);
}
 
// ################################################
// Implementação dos seus algoritmos:
   
// heapify: verifica se o elemento na posição passada é um heap e se não for transforma-o em um
// parâmetros: array, índice do elemento a heapificar, tamanho do heap, dicionário de logs
void heapify(array_t& array, element_t elemento, int heap_size, loginfo_t& loginfo){
    // a implementar
}
 
int heap_max(array_t& heap, loginfo_t& loginfo){
    // A implementar!    
    return -1;
}

int extract_max(array_t& heap, loginfo_t& loginfo){    
   // A implementar!
   return -1;
}
 
void heap_insert(array_t& heap, element_t elemento, loginfo_t& loginfo){
   // A implementar!
}
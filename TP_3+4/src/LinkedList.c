#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0; // cuando creo la linkedlist, tiene 0 nodos
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	//el tamaño del ll indica cuantos nodos tiene => puedo usarlo como indice
	Node* pNodoObtenido = NULL; //inicializo el puntero
	int lenLinkedList;
	if(this != NULL)
	{
		lenLinkedList = ll_len(this);
		if(nodeIndex>=0 && nodeIndex<lenLinkedList)
		{ //si paso todas las validaciones puedo recorrer la lista (desde  la cabeza)
			pNodoObtenido = this->pFirstNode; //estoy ubicado en la cabeza y a pNodoObtenido lo ubico en el primer nodo (el de indice 0)
			//si nodeIndex==0, no entro al for
			//estoy en la cabeza y guardo nodo1
			for(int i=0; i<nodeIndex; i++)
			{
				pNodoObtenido = pNodoObtenido->pNextNode;
			}
			//si nodeIndex==2 => nodo3
			//i=0 => estoy en nodo1 y guardo nodo2
			//i=1 => estoy en nodo2 y guardo nodo3
			//i=2 => no entro al for
			//=>devuelvo el nodo3
		}
	}
    return pNodoObtenido;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int lenLinkedList;
    Node* pAuxNodoSiguiente = NULL;
    Node* pAuxNodoAnterior = NULL;
    Node* pNewNode = NULL;
    if(this != NULL) //&& pElement != NULL)
    {
    	lenLinkedList = ll_len(this);
    	if( nodeIndex>=0 && nodeIndex<=lenLinkedList) //necesito el = para poder agregar un nodo al final de la lista. En este caso, ese len seria el indice el nuevo nodo
    	{
    		pNewNode = (Node*) calloc(1, sizeof(Node)); //reservo el espacio para un nuevo nodo

    		if(pNewNode != NULL)
    		{
    			pAuxNodoSiguiente = getNode(this, nodeIndex); //guardo al nodo que está donde va a estar el nuevo nodo. A este lo voy a mover "hacia adelante"
    			pNewNode->pElement = pElement; //le asigno el elemento al nodo
    			pNewNode->pNextNode = pAuxNodoSiguiente;
    		}
    		//ahora debo ver que pasa con el nodo ubicado en el indice anterior al que estoy tratando de crear. Puede pasar que
    		//1.El nodo que este intentando crear se ubique en el primer lugar
    		if(nodeIndex == 0)
    		{
    			this->pFirstNode = pNewNode;
    		}
    		//2.Que no sea el primer nodo
    		else
    		{
    			pAuxNodoAnterior = getNode(this, nodeIndex-1);//guardo el nodo que está antes de la posicion que va a ocupar el nuevo nodo.
    			pAuxNodoAnterior->pNextNode = pNewNode;
    		}
    		//ya ubicado el nodo en la lista, la agrando
    		this->size++;
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{//agrego un elemento al final de la lista
    int returnAux = -1;
    int lenLinkedList;
    if(this != NULL) //&&pElement != NULL)
    {
    	lenLinkedList = ll_len(this); //necesito el tamano total que sera el indice del ultimo nodo
    	returnAux=addNode(this, lenLinkedList, pElement);
    }
    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode = NULL;
    int lenLinkedList;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this); //necesito el tamano para solo para validar el indice
    	if(index>=0 && index<lenLinkedList)
    	{
    		pAuxNode = getNode(this, index); //en al auxiliar guardo la dir del nodo cuyo indice recibi por parametro
    		if(pAuxNode != NULL)
    		{
    			returnAux = pAuxNode->pElement; //le asigno al puntero que retorno el elemento del nodo que devolvio getNode
    		}
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int lenLinkedList;
    Node* pAuxNode = NULL;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this); //lo uso para validar index
    	if(index >= 0 && index<lenLinkedList)
    	{
    		pAuxNode = getNode(this, index);
    		if(pAuxNode != NULL)
    		{
    			pAuxNode->pElement = pElement;
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//análoga a addNode
{
    int returnAux = -1;

    Node* pNodoABorrar = NULL;
    Node* pAuxNodoAnterior = NULL;
    Node* pAuxNodoSiguiente = NULL;
    int lenLinkedList;

    if(this != NULL)
    {
    	lenLinkedList = ll_len(this);
    	if(index>=0 && index<lenLinkedList)
    	{
    		pNodoABorrar = getNode(this, index);
    		if(pNodoABorrar != NULL)
    		{
    			pNodoABorrar = getNode(this, index); //guardo la direcion del nodo que voy a borrar
    			pAuxNodoSiguiente = pNodoABorrar->pNextNode; //el nodo que estaba despues del que estaba borrando pasa a ocupar su lugar. Si estoy borrando el ultimo nodo, pNextNode == NULL
    		}
    		//Al borrar pueden pasar dos cosas:
    		//1.El nodo que este intentando borrar se ubique en el primer lugar
    		if(index == 0)
    		{
    			this->pFirstNode = pAuxNodoSiguiente; //guardo como primer nodo el nodo siguiente al que estoy borrando
    		}
    		//2.Que no sea el primer nodo
    		else
    		{
    			pAuxNodoAnterior = getNode(this, index-1); //el nodo anterior es el de indice-1 al que estoy borrando
    			pAuxNodoAnterior->pNextNode = pAuxNodoSiguiente; //al nodo anterior le asigno como pNextNode el siguiente nodo al que borré, que ahora estara en lugar del nodo borrado
    		}
    		//ya borrado el nodo de la lista, la achico
    		this->size--;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int retornoEliminacion;
    if(this != NULL)
    {

    	while(ll_len(this)>0)
    	{
    		retornoEliminacion = ll_remove(this, 0);//elimino siempre el primero
    	}
    	if(ll_len(this)==0 && retornoEliminacion == 0)
    	{
    		returnAux = 0; //devuelve cero cuando la lista no tiene elementos -Y- se realizo la ultima eliminacion (si se elimino el ultimo, se eliminaron los anteriores si hubieran)
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(ll_clear(this) == 0) //se completó el vaciado de la lista => libero la memoria reservada para la linkedlist
    	{
    		free(this);
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenLinkedList;
    void* pAuxElement = NULL;
    if(this != NULL) //&& pElement != NULL)
    {
    	lenLinkedList = ll_len(this);
    	for(int index=0; index<lenLinkedList; index++)
    	{
    		pAuxElement = ll_get(this, index);
    		if(pAuxElement == pElement)
    		{
    			returnAux = index;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; //error
    if(this != NULL)
    {
    	if(this->size == 0) //lista vacia
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;//lista no vacia
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	//el nodo de indice index antes del push lo voy a "mover hacia adelante"
    int returnAux = -1;
    int lenLinkedList;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this);
    	if(index>=0 && index<=lenLinkedList)
    	{
    		returnAux = addNode(this, index, pElement); //agrego un nodo en la posicion index. Los corrimientos de los nodos los realiza la funcion
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int lenLinkedList;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this);
    	if(index>=0 && index<=lenLinkedList)
    	{
    		returnAux = ll_get(this, index); //guardo y retorno el puntero al elemento que estoy eliminando de la lista
    		if(returnAux != NULL)
			{
				ll_remove(this, index); //lo elimino de la lista
			}
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL) //&&pElement != NULL)
    {
    	returnAux = 0; //dado que ya paso la validacion, puedo asegurar que, en este punto, no contiene el elemento
    	if(ll_indexOf(this, pElement)!=-1)
    	{
    		returnAux = 1; //ll_index encontró el indice de pElement
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int lenLinkedList2;
    void* pAuxElement = NULL;
    if(this != NULL && this2 != NULL)
    {
    	lenLinkedList2 = ll_len(this2);
    	returnAux = 0; //ya paso las validaciones. En este punto puedo asegurar que this1 no contiene a this2. Lo cambiaré solo si lo contiene
    	for(int i=0; i<lenLinkedList2; i++)
    	{
    		pAuxElement = ll_get(this2, i); //guardo en pAuxElement el elemento de indice i de la lista this2
    		returnAux = ll_contains(this, pAuxElement); //veo si el elemento anterior de la lista this2 esta contenido en la lista this
    		if(returnAux == 0) //en cuanto aparezca el primer elemento de this2 que no este contenido en this1, cambio el estado de returnAux y rompo la iteracion
    		{
    			break;
    		}
    	}
    }
    return returnAux;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Eror: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAuxElement = NULL;
    int lenLinkedList;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this);
    	if(from>=0 && from<lenLinkedList && to<=lenLinkedList && to>from) //valido los limites
    	{
    		cloneArray = (LinkedList*) ll_newLinkedList(); //creo la lista
    		if(cloneArray != NULL)
    		{
				for(int i=from; i<to; i++)
				{
					pAuxElement = ll_get(this, i);//cargo en pAuxElement cada elemento de indice i
					if(pAuxElement != NULL)
					{
						ll_add(cloneArray, pAuxElement); //agrego el elemento a la lista
					}
				}
    		}
    	}
    }
    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int lenLinkedList;
    if(this != NULL)
    {
    	lenLinkedList = ll_len(this);//sera el "to" de la sublista
    	cloneArray = ll_subList(this, 0, lenLinkedList); //hago una sublista que va de 0 hasta el tamaño de la linkedlist original
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int lenLinkedList;
    void* aux1 = NULL;
    void* aux2 = NULL;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	lenLinkedList = ll_len(this);
    	for(int i=0; i<lenLinkedList-1; i++)
    	{
    		for(int j=i+1; j<lenLinkedList; j++)
    		{
    			aux1 = ll_get(this, i);
    			aux2 = ll_get(this, j);
    			if((order == 1) && (pFunc(aux1, aux2)==1)) //ascendente - aux1>aux2 y necesito aux1<aux2
    			{
					ll_set(this, i, aux2);//en el indice de aux1 guardo a aux2
					ll_set(this, j, aux1);//en el indice de aux2 guardo a aux1
					returnAux = 0;
    			}
    			if((order == 0) && (pFunc(aux1, aux2)==-1))//descendente - aux1<aux2 y necesito aux1>aux2
    			{//hago el swap
					ll_set(this, i, aux2);//en el indice de aux1 guardo a aux2
					ll_set(this, j, aux1);//en el indice de aux2 guardo a aux1
					returnAux = 0;
    			}
    		}
    	}
    }
    return returnAux;
}

#ifndef __DLIST_H__
#define __DLIST_H__


/**********************************************************
 * INSTRUCTOR NOTE: Do not modify the class declarations! *
 * The class Dlist is a class template.                   *
 *********************************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  // Maintenance methods

  Dlist();                                // constructor
  Dlist(const Dlist &l);                  // copy constructor
  Dlist &operator=(const Dlist &l);       // assignment
  ~Dlist();                               // destructor

  // Operational methods

  // EFFECTS: returns true if list is empty, false otherwise
  bool IsEmpty() const;

  // MODIFIES: this
  // EFFECTS: inserts o at the front of the list
  void InsertFront(const T &o);

  // MODIFIES: this
  // EFFECTS: inserts o at the back of the list
  void InsertBack(const T &o);

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveFront();

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveBack();

 private:
  // A private type

  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  // Private member variables

  node   *first; // The pointer to the first node (NULLptr if none)
  node   *last;  // The pointer to the last node (NULLptr if none)

  // Private utility methods

  // EFFECTS: called by constructors to establish empty list invariant
  void MakeEmpty();

  // EFFECTS: called by copy constructor/operator= to copy nodes
  //          from a source instance l to this instance
  void CopyAll(const Dlist &l);
    
  // EFFECTS: called by destructor and operator= to remove and destroy
  //          all list nodes
  void RemoveAll();
};

// Constructor
template <typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
}

// Copy constructor
template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  MakeEmpty();
  CopyAll(l);
}

// Assignment operator
template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist<T> &l) {
  if (this != &l) {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

// Destructor
template <typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/**********************************************************
 * INSTRUCTOR NOTE: Implement the member functions below. *
 * These member functions are all function templates.     *
 *********************************************************/

// EFFECTS: returns true if list is empty, false otherwise
template <typename T>
bool Dlist<T>::IsEmpty() const {
  // Implement this function.
    if ((first == NULL) && (last == NULL))
        return true;
    else
        return false;
}

// MODIFIES: this
// EFFECTS: inserts o at the front of the list
template <typename T>
void Dlist<T>::InsertFront(const T& o) {
  // Implement this function.
    node* temp_pointer = new node;
    temp_pointer->o = o;

    if (first == NULL)
        first = last = temp_pointer;
    else {
        first->prev = temp_pointer;
        temp_pointer->next = first;
        first = temp_pointer;
    }
}

// MODIFIES: this
// EFFECTS: inserts o at the back of the list
template <typename T>
void Dlist<T>::InsertBack(const T& o) {
  // Implement this function.
    node* temp_pointer = new node;
    temp_pointer -> o = o;

    if (last == NULL) {
        first = last = temp_pointer;
    }
    else {
        last->next = temp_pointer;
        temp_pointer->prev = last;
        last = temp_pointer;
    }
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveFront() {
  // Implement this function.
    if (!IsEmpty()) {
        node* temp_pointer = first;
        T deleted_value = temp_pointer->o;

        if(first == last){
          last = NULL;
          first = NULL;
        }
        else {
          first = first->next;
          first->prev = NULL;
        }
          
        delete temp_pointer;
        return deleted_value;
    }
    else
        throw;
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveBack() {
  // Implement this function.
    if (!IsEmpty()) {
        node* temp_pointer = last;
        T deleted_value = temp_pointer->o;

        if (first == last) {
          first = NULL;
          last = NULL;
        }
        else {
          last = last->prev;
          last->next = NULL;
        }
        
        delete temp_pointer;
        return deleted_value;
    }
    else
        throw;
}

// EFFECTS: called by constructors to establish empty list invariant
template <typename T>
void Dlist<T>::MakeEmpty() {
  // Implement this function.
    first = NULL;
    last = NULL;
}

// EFFECTS: called by copy constructor/operator= to copy nodes
//          from a source instance l to this instance
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l) {
  // Implement this function.
    RemoveAll();
    node* temp_pointer = l.first;
    
    while (temp_pointer != NULL) {
        T old = temp_pointer->o;
        InsertBack(old);
        temp_pointer = temp_pointer->next;
    }
}

// EFFECTS: called by destructor and operator= to remove and destroy
//          all list nodes
template <typename T>
void Dlist<T>::RemoveAll() {
  // Implement this function.
    while (!IsEmpty()) {
        RemoveFront();
    }
}

/**** INSTRUCTOR NOTE: DO NOT DELETE #endif FROM END OF FILE. ****/
#endif /* __DLIST_H__ */

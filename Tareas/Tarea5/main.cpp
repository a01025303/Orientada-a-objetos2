#include "listInterface.h"

int main()
{
    /*
    listElement pear("Pear"); 
    listElement mango("Mango");
    listElement banana("Banana"); 
    listElement berry("Berry"); 
    listElement orange("Orange"); 
    listElement watermelon("Watermelon"); 
    listElement pineapple("Pineapple"); 
    listElement mango2("Mango"); 
    //cout << apple.getElementIdentifier() << endl; 
    //cout << apple.getNext() << endl; 
    linkedList fruits(&apple); 
    //fruits.Print(); 
    fruits.Add(&pear); 
    fruits.Add(&mango); 
    fruits.Add(3, &banana);
    fruits.Add(&berry); 
    fruits.Add(2, &orange); 
    fruits.Add(&watermelon); 
    fruits.Add(&pineapple); 
    fruits.Add(&mango2); 
    fruits.Print(); 
    cout << fruits.Size() << endl; 
    fruits.Remove(5); 
    fruits.Print();
    fruits.Get(2); 
    //fruits.Size(); 
    //cout << mango.getIndex() << endl; */
    ListElement apple("Apple"); 
    ListElement pear("Pear"); 
    ListElement mango("Mango");
    ListElement banana("Banana"); 
    ListElement berry("Berry"); 
    ListElement orange("Orange"); 
    ListElement watermelon("Watermelon"); 
    ListElement pineapple("Pineapple"); 
    ListElement mango2("Mango"); 
    ListInterface* fruits = new LinkedList(&apple);
    fruits->Add(&pear); 
    fruits->Print(); 
    fruits->Remove(1); 
    fruits->Print(); 
    fruits->Add(&apple); 
    fruits->Print(); 
    fruits->Get(4); 
    delete fruits; 
}
#include "streaming.h"

//LIST ELEMENT

//Constructores de ListElement
ListElement::ListElement(){}
ListElement::ListElement(string elNombre): name(elNombre), nextElement(NULL){}

//Getter de identificador de elemento
string ListElement::getName()
{
    return name;
}
//Getter de siguiente elemento
ListElement* ListElement::getNext()
{   
    return nextElement; 
}




//LINKED LIST

//Constructor de LinkedList
LinkedList::LinkedList():firstElement(0){} 
LinkedList::LinkedList(ListElement* first) : firstElement(first){} 

//Método para agregar elemento al final de la fila 
void LinkedList::Add(ListElement* element)
{
    //Si no hay elementos en la lista
    if (firstElement == NULL)
    {
        //El elemento que se agrega es el nuevo primer elemento
        firstElement = element; 
    }
    else
    {
        //Inicializar variable auxiliar para ir al siguiente elemento
        ListElement* siguiente = firstElement; 
        //Iterar en los elementos de la fila
        while (siguiente != NULL)
        {
            //Condición para agregar el elemento al final 
            if (siguiente->nextElement == NULL)
            {
                //El siguiente elemento del elemento en el que nos encontramos actualmente, se convierte en el elemento a agregar
                siguiente->nextElement = element;  
                //Romper ciclo
                break;
            }
            //Ir al siguiente elemento
            siguiente = siguiente->getNext();
        }
    }
}


//Agregar elemento en posición determinada
void LinkedList::Add(int position, ListElement* element)
{
    //Si no hay elementos en la lista 
    if (firstElement == NULL)
    {
        //El elemento que se agrega es el nuevo primer elemento
        firstElement = element; 
    }
    else
    {
        //Obtener tamaño de la lista
        int size = Size(); 
        //Inicializar variables auxiliares
        int index = 1;
        ListElement* siguiente = firstElement; 
        //Iterar en los elementos
        while (siguiente != NULL)
        {
            //Condición para posición = 1
            if ((position == index) && (index == 1))
            {
                //Hacer que el elemento proporcionado sea el nuevo primer elemento
                firstElement = element; 
                // El siguiente elemento es el antiguo primer elemento
                firstElement->nextElement = siguiente; 
            }
            //Condición para posición de elemento existente a partir de 2
            else if (index == position - 1)
            {
                //Variable auxiliar para guardar el valor del siguiente elemento de "siguiente"
                ListElement* nextNext = siguiente->getNext();
                //Asignar ahora que el siguiente elemento de "siguiente" sea element
                siguiente->nextElement = element; 
                //El elemento después de element será nextNext
                element->nextElement = nextNext;
                //Ir al siguiente elemento
                siguiente = siguiente->getNext(); 
            }
            //Condición para ver si existe un siguiente elemento
            if (siguiente->nextElement == NULL)
            {
                //Si la posición es mayor al tamaño de la lista 
                if (position > size)
                {
                    //Poner nuevo elemento al final 
                    siguiente->nextElement = element;
                    //Romper
                    break; 
                } 
            }
            //Ir al siguiente elemento
            siguiente = siguiente->getNext(); 
            //Si el siguiente elemento es nulo
            if (siguiente == NULL)
            {
                //Romper
                break; 
            }
            //Aumentar index en 1
            index = index + 1;
        }
    }
}

//Obtener un elemento de la lista a partir de su posición 
ListElement* LinkedList::Get(int index)
{
    //Inicializar variables auxiliares 
    int ind = 1;  
    ListElement* siguiente = firstElement; 
    //Condición en caso de tener una lista vacía
    if (siguiente == 0)
    {
        cout << "Esta lista no tiene elementos" << endl; 
    }
    //Iterar en los elementos
    while (siguiente != 0)
    {
        //Condición para ubicar el índice requerido
        if (ind == index)
        {
            return siguiente; 
        }
        //Ir al siguiente elemento
        siguiente = siguiente->getNext(); 
        //Condición para cerrar ciclo --> si llegamos a este punto, es porque ind e index nunca fueron iguales, o sea no existe un elemento con index
        if (siguiente == NULL)
        {
            //Mensaje 
            cout << "No existen elementos con ese índice" << endl; 
            //Romper
            break;
        }
        //Ind + 1
        ind ++; 
    }
    return siguiente; 
} 

//Eliminar elemento dado el índice
void LinkedList::Remove(int index)
{
    //Tamaño de la lista
    int size = Size(); 
    //Inicializar variables auxiliares
    int ind = 1;
    ListElement* siguiente = firstElement; 
    //iterar elementos
    while (siguiente != NULL)
    {
        //Condición si se quiere eliminar el primer elemento
        if (index == ind && ind == 1)
        {   //Ir al siguiente elemento (elemento 2)
            siguiente = siguiente->getNext();
            // Hacer que el primer elemento deje de apuntar a cualquier lado
            firstElement->nextElement = NULL; 
            //Hacer que el elemento 2 sea el nuevo primer elemento 
            firstElement = siguiente; 
            ind++; 
            //siguiente = siguiente->getNext();
        }
        //Condición si se quiere eliminar cualquier elemento en medio de la lista
        if (ind == index - 1)
        {
            //Queremos guardar el siguiente del elemento que se quiere borrar en una variable
            //Como estamos en un elemento antes del que queremos borrar, tenemos que usar getNext() dos veces
            ListElement* nextNext = siguiente->getNext()->getNext();
            //Variable auxiliar para ir al elemento que se quiere eliminar
            ListElement* aEliminar = siguiente->getNext();
            //Hacer que el elemento que se quiere eliminar, deje de apuntar a cualquier lado
            aEliminar->nextElement = NULL; 
            // Ahora, hacemos que el elemento en el que estamos (el elemento anterior al que se quiere borrar) apunte a nextNext
            siguiente->nextElement = nextNext;  
            //Si el index elegido es menor al tamaño de la lista, ir al siguiente, si no,  no se puede ir al siguiente porque no existe 
            if (index < size)
            {
                //Ir al siguiente elemento
                siguiente = siguiente->getNext(); 
            }
        }
        //siguiente elemento
        siguiente = siguiente->getNext();
        //Condición si se quiere eliminar un elemento inexistente
        if (index > size)
        {
            cout << "No existe ese elemento" << endl; 
            break;
        }
        //Cerrar ciclo
        if (siguiente == NULL)
        {
            break; 
        }
        //ind + 1
        ind++;  
    }
}

//Tamaño de una lista
int LinkedList::Size()
{
    //Inicializar variables auxiliares
    ListElement* siguiente = firstElement; 
    int count = 0; 
    //Iterar elementos
    while (siguiente != 0)
    {
        //Agregar 1 al contador
        count ++;
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Condición para el final de la lista
        if (siguiente == NULL)
        {
            return count;
        }
    }
    return count; 
} 
void LinkedList::Print()
{
    //Inicializar variable auxiliar
    ListElement* siguiente = firstElement; 
    //Inicializar contador
    int count = 1; 
    //Iterar elementos
    while (siguiente != 0)
    {
        //Imprimir cada elemento con su índice
        cout << count << ". " << siguiente->getName() << endl; 
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Agregar 1 a count
        count ++; 
        //Cerrar ciclo al terminar la lista
        if (siguiente == NULL)
        {
            break;
        }
    }
}





//STREAMING MANAGER

//Constructor del manager
StreamingManager::StreamingManager(): videoList(new LinkedList){}

//Agregar video al final de la lista
void StreamingManager::addVideo(Video* theVideo)
{
    //Usar método ADD
    videoList->Add(theVideo);
}

//Agregar video en una posición de la lista 
void StreamingManager::addVideo(int theNumber, Video* theVideo)
{
    //Usar método ADD con parámetro de posición
    videoList->Add(theNumber, theVideo);
}

//Método para imprimir todos los videos
void StreamingManager::printVideos()
{
    //Determinar tamaño de la lista de videos
    int count = videoList->Size(); 
    //Ciclo para pasar por cada video 
    for (int i = 1; i <= count; i++)
    {
        //Variables para determinar si se trata de una película o una serie 
        Movie* movies = dynamic_cast<Movie*>(videoList->Get(i));
        Serie* series = dynamic_cast<Serie*>(videoList->Get(i));
        //Si no es una película devuelve 0
        if (movies != 0)
        {
            //Imprimir datos solicitados de la película
            cout << movies->getName() << " (" << movies->getIdentifier() << ") ........  " << movies->getRating() << endl; 
        }
        //Si no es una serie, devuelve 0
        if (series != 0)
        {
            //Imprimir datos solicitados de la serie
            cout << series->getName() << " (" << series->getIdentifier() << ") ........  " << series->getRating() << endl; 
        }
    }
}

//Método que imprime solo películas
void StreamingManager::printMovies()
{
    //Determinar tamaño de la lista
    int count = videoList->Size(); 
    //Iterar en todos los videos 
    for (int i = 1; i <= count; i++)
    {
        //Variable de downcasting para obtener película
        Movie* movies = dynamic_cast<Movie*>(videoList->Get(i));
        //Condición para verificar que es una película 
        if (movies != 0)
        {
            //Imprimir película con datos
            cout << movies->getName() << " (" << movies->getIdentifier() << ") ........  " << movies->getRating() << endl; 
        }
    }
}


//Método para imprimir series 
void StreamingManager::printSeries()
{
    //Obtener tamaño de la lista
    int count = videoList->Size(); 
    //Iterar en todos los videos
    for (int i = 1; i <= count; i++)
    {
        //Variable para obtener serie
        Serie* series = dynamic_cast<Serie*>(videoList->Get(i));
        //Condición para verificar que se trate de una serie
        if (series != 0)
        {
            //Imprimir serie
            cout << series->getName() << " (" << series->getIdentifier() << ") ........  " << series->getRating() << endl; 
        }
    }
}


//Método para agregar episodio
void StreamingManager::addEpisode(Serie* theSerie, Episode* theEpisode)
{
    //Poner en la lista de episodios un episodio usando ADD
    theSerie->getEpisodeList()->Add(theEpisode); 
}

//Método para imprimir episodios
void StreamingManager::printSerieEpisodes(Serie* theSerie)
{
    //Ver tamaño de la lista de episodios 
    int count = theSerie->getEpisodeList()->Size(); 
    //Si el tamaño es 0, especificar que no tiene episodios 
    if (count == 0)
    {
        cout << "Esta serie no tiene episodios" << endl; 
    }
    //Ciclo para iterar en los episodios
    for (int i = 1; i <= count; i++)
    { 
        //Variable para obtener episodio
        Episode* episodes = dynamic_cast<Episode*>(theSerie->getEpisodeList()->Get(i)); 
        //Condición para verificar que sea un episodio (solo por si acaso)
        if (episodes != 0)
        {
            //Imprimir episodio con su info
            cout << "T" << episodes->getSeasonNum() << " " << episodes->getName() << "...... " << episodes->getEpisodeRating() << endl; 
        }
    }
    
}

//Sacar promedio de los ratings de videos 
float StreamingManager::videoRatingMean()
{
    //Obtener tamaño de la lista de videos
    int count = videoList->Size(); 
    //Inicializar variable suma para sumar ratings
    int sum = 0; 
    //Iterar la lista
    for (int i = 1; i <= count; i++)
    {
        //Obtener videos
        Video* videos = dynamic_cast <Video*> (videoList->Get(i)); 
        //Actualizar suma de ratings
        sum = sum + videos->getRating(); 
    }
    //Devolver el promedio
    return float(sum)/float(count); 
}

//Obtener el promedio de ratings de calificaciones
float StreamingManager::episodesMean(Serie* theSerie)
{
    //Obtener tamaño de la lista de episodios 
    int count = theSerie->getEpisodeList()->Size(); 
    //Inicializar variable para suma de ratings
    int sum = 0; 
    //Iterar en la lista de episodios
    for (int i = 1; i <= count; i++)
    {
        //Obtener episodio
        Episode* episodes = dynamic_cast<Episode*>(theSerie->getEpisodeList()->Get(i));
        //Actualizar suma de episodios 
        sum = sum + episodes->getEpisodeRating(); 
    }
    //Obtener promedio
    return float(sum)/float(count); 
}

//Obtener la información de un video al buscarlo por nombre
void StreamingManager::searchVideosByName(string theName)
{
    //Obtener tamaño de la lista de videos 
    int count = videoList->Size(); 
    //Iterar en la lista de videos 
    for (int i = 1; i <= count; i++)
    {
        //Obtener películas o series (si no es película, devuelve 0 el dynamic casting; lo mismo con series)
        Movie* movies = dynamic_cast<Movie*>(videoList->Get(i));
        Serie* series = dynamic_cast<Serie*>(videoList->Get(i));
        //Condición para película
        if (movies != 0)
        {
            //Condición para verificar que el nombre sea el que están buscando
            if (movies->getName() == theName)
            {
                //Imprimir película con su info
                cout << movies->getName() << " (" << movies->getIdentifier() << ") ........ " << movies->getRating() << endl;  
            }
        }
        //Condición para serie
        if (series != 0)
        {
            //Condición para verificar que el nombre sea el que están buscando
            if (series->getName() == theName)
            {
                //Imprimir serie con su info
                cout << series->getName() << " (" << series->getIdentifier() << ") ........ " << episodesMean(series) << endl; 
                //Imprimir serie con sus episodios
                printSerieEpisodes(series); 
            }
        }
    }
    
}





//VIDEO

//Constructores Video
Video::Video(){} 
Video::Video(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
        string theProdC, string theDir, char theIdent): ListElement(theName), genre(theGenre), duration(theDur), rating(theRating), 
        id(theID), releaseYear(theRelY), classification(theClassification), productionCompany(theProdC), director(theDir), identifier(theIdent){} 

//Getters
string Video::getGenre()
{
    return genre; 
} 
float Video::getDuration()
{
    return duration; 
} 
float Video::getRating()
{
    return rating; 
} 
int Video::getID()
{
    return id; 
}
int Video::getReleaseYear()
{
    return releaseYear;
}
string Video::getClassification()
{
    return classification; 
}
string Video::getProductionCompany()
{
    return productionCompany;
} 
string Video::getDirector()
{
    return director;
}
char Video::getIdentifier()
{
    return identifier;
} 
Video* Video::getNextVideo()
{
    return nextVideo;
}

//Setters
void Video::setGenre(string theGenre)
{
    genre = theGenre;
}
void Video::setDuration(float theDuration)
{
    duration = theDuration;
} 
void Video::setRating(float theRating)
{
    rating = theRating;
}
void Video::setID(int theID)
{
    id = theID;
}
void Video::setReleaseYear(int theReleaseYear)
{
    releaseYear = theReleaseYear;
}
void Video::setClassification(string theClassification)
{
    classification = theClassification;
}
void Video::setProductionCompany(string theProductionCompany)
{
    productionCompany = theProductionCompany;
}
void Video::setDirector(string theDirector)
{
    director = theDirector;
} 
void Video::setIdentifier(char theIdentifier)
{
    identifier = theIdentifier;
}
void Video::setNextVideo(Video* theVideo)
{
    nextVideo = theVideo; 
} 








//MOVIE

//Constructores movie
Movie::Movie(): Video("Black Widow", "Action", 160, 5, 2192, 2021, "PG13", "Disney", "Juanito", 'P') {}
Movie::Movie(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
    string theProdC, string theDir, char theIdent): Video(theName, theGenre, theDur, theRating, theID, theRelY, theClassification, 
    theProdC, theDir, theIdent){}




//SERIE

//Constructores serie
Serie::Serie(): Video("Friends", "Comedy", 173, 5, 3019, 2000, "PG13", "Warner Bros.", "Juanito", 'S'), episodeList(new LinkedList) {}
Serie::Serie(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
    string theProdC, string theDir, char theIdent): Video(theName, theGenre, theDur, theRating, theID, theRelY, theClassification, 
    theProdC, theDir, theIdent), episodeList(new LinkedList){}

//Obtener lista de episodios 
ListInterface* Serie::getEpisodeList()
{
    return episodeList;
}





//EPISODE
Episode::Episode(): ListElement("Pilot"), episodeDuration(22), episodeRating(2), seasonNumber(1){}
Episode::Episode(int theSeasonNumber, string theEpisodeName, float theEpisodeDuration, float theEpisodeRating): ListElement(theEpisodeName), 
episodeDuration(theEpisodeDuration), episodeRating(theEpisodeRating), seasonNumber(theSeasonNumber){}

//Getters
int Episode::getSeasonNum()
{
    return seasonNumber;
} 
float Episode::getEpisodeDuration()
{
    return episodeDuration;
} 
float Episode::getEpisodeRating()
{
    return episodeRating;
}

//Setters
void Episode::setSeasonNum(int theSeasonN)
{
    seasonNumber = theSeasonN; 
}
void Episode::setEpisodeDuration(float theEpisodeDuration)
{
    episodeDuration = theEpisodeDuration; 
}
void Episode::setEpisodeRating(float theEpisodeRating)
{
    episodeRating = theEpisodeRating; 
}

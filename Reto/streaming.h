#include <iostream>
#include <string>

using namespace std; 

#pragma once

class Video; 
class Movie; 
class Serie; 
class Episode; 
class ListElement
{
    protected: 
        //Atributos
        string name; //Nombre/identificador
        ListElement* nextElement; //Siguiente elemento
    public: 
        friend class LinkedList; //Perminte que linkedlist vea 
        ListElement(); //Constructor vacío
        ListElement(string theName);  //Constructor con parámetros
        string getName(); //Obtener nombre
        ListElement* getNext(); //Obtener siguiente elemento
        virtual ~ListElement(){} //Destructor virtual
};

class ListInterface
{
    public: 
        //Clase abstracta, metodos virtuales puros
        virtual void Add(ListElement* element) = 0; //Agrega elemento al final de la lista
        virtual void Add(int position, ListElement* element) = 0; //Agrega elemento en la posición especificada
        virtual ListElement* Get(int theIndex) = 0; //Devuelve elemento en una posición determinada
        virtual void Remove(int index) = 0; //Borra elemento de la posición especificada
        virtual int Size() = 0; //Devuelve cantidad de elementos
        virtual void Print() = 0; //Implime elementos
        virtual ~ListInterface(){} //Destructor virtual
};

class LinkedList: public ListInterface
{
    protected: 
        //Atributos
        ListElement* firstElement;  
    public: 
        LinkedList(); //Constructor default
        LinkedList(ListElement* first); //Constructor con parámetros

        //Implementaciones de métodos de ListInterface
        void Add(ListElement* element); 
        void Add(int position, ListElement* element); 
        ListElement* Get(int theIndex); 
        void Remove(int index); 
        int Size(); 
        void Print();
};

class StreamingManager
{
    protected: 
        //Atributo
        ListInterface* videoList;
    public: 
        StreamingManager();  //Constructor default
        void addVideo(Video* theVide); //Agregar video al final de la lista
        void addVideo(int thePosition, Video* theVideo); //Agregar video en posición especificada
        void addEpisode(Serie* theSerie, Episode* theEpisode); //Agregar episodio a una serie
        void printVideos(); //Imprimir todos los videos 
        void printMovies(); //Imprimir solo películas
        void printSeries(); //Imprimir solo series
        void printSerieEpisodes(Serie* theSerie); //Imprimir episodios de una serie
        float videoRatingMean(); //Obtener el rating promedio de todos los videos
        float episodesMean(Serie* theSerie); //Obtener el rating promedio de todos los episodios de una serie
        void searchVideosByName(string theName); //Buscar videos por nombre
        ~StreamingManager(){delete videoList;} //Destructor que borra lista de videos 
}; 


class Video : public ListElement
{
    protected: 
        //Atributos
        string genre; //Género del video 
        float duration; //Duración del video
        float rating; //Calificación del video (1-5)
        int id; //ID del video
        int releaseYear; //Año en el que salió el video
        string classification; //Clasificación del video (PG, R, etc)
        string productionCompany; //Compañía que produjo el video
        string director; //Director del video 
        char identifier; //Tipo de video (en nuestro caso, película P o serie S)
        Video* nextVideo; //Apuntador al siguiente video
    public: 
        //Constructores 
        Video(); 
        Video(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
        string theProdC, string theDir, char theIdent); 

        //Destructor
        ~Video(){}

        //Getters
        string getGenre(); 
        float getDuration(); 
        float getRating(); 
        int getID();
        int getReleaseYear(); 
        string getClassification(); 
        string getProductionCompany(); 
        string getDirector(); 
        char getIdentifier(); 
        Video* getNextVideo(); 

        
        //Setters
        void setGenre(string theGenre); 
        void setDuration(float theDuration); 
        void setRating(float theRating);  
        void setID(int theID); 
        void setReleaseYear(int theReleaseYear); 
        void setClassification(string theClassification);
        void setProductionCompany(string theProductionCompany); 
        void setDirector(string theDirector); 
        void setIdentifier(char theIdentifier); 
        void setNextVideo(Video* theVideo); 
};

class Movie: public Video
{
    //Tiene los mismos atributos y métodos que el video 
    public: 
    //Constructores
    Movie(); 
    Movie(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
        string theProdC, string theDir, char theIdent); 
}; 

class Serie: public Video
{
    protected: 
        //Atributos
        ListInterface* episodeList; //lista de episodios
    public: 
        //Constructores
        Serie();
        Serie(string theName, string theGenre, float theDur, float theRating, int theID, int theRelY, string theClassification, 
        string theProdC, string theDir, char theIdent); 
        //Getter
        ListInterface* getEpisodeList(); //Obtener lista de episodios
        //Destructor 
        ~Serie(){delete episodeList;} //Eliminar lista de episodios
};

class Episode: public ListElement
{
    protected: 
        //Atributos
        int seasonNumber; //Número de temporada
        float episodeDuration; //Duración 
        float episodeRating; //Rating individual
    public: 
        //Constructores
        Episode(); 
        Episode(int theSeasonNumber, string theEpisodeName, float theEpisodeDuration, float theEpisodeRating);

        //Getters
        int getSeasonNum(); 
        float getEpisodeDuration(); 
        float getEpisodeRating(); 

        //Setters
        void setSeasonNum(int theSeasonN);
        void setEpisodeDuration(float theEpisodeDuration);
        void setEpisodeRating(float theEpisodeRating); 
}; 
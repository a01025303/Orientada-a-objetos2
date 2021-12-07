#include "streaming.h"

int main()
{
    //Crear algunas películas, series y sus capítulos
    Movie CaptainAmerica("Captain America", "Action", 125.0, 5, 1234, 2009, "PG", "Marvel", "Juanito", 'P');
    Movie TheSoundOfMusic("The Sound of Music", "Romance", 172.0, 4, 2000, 1965, "G", "Robert Wise Productions", "Robert Wise", 'P');
    Movie GrownUps("Grown Ups", "Comedy", 102.0, 3, 3000, 2010, "PG-13", "Columbia Pictures", "Dennis Dugan", 'P'); 
    Serie ParksAndRec("Parks and Recreation", "Comedy", 1010, 3, 3000, 2010, "PG-13", "Columbia Pictures", "Dennis Dugan", 'S');
    Serie Friends("Friends", "Comedy", 1781, 4, 3001, 1990, "PG-13", "Universal studios", "Martha Krane", 'S');
    Episode pilot(1, "Pilot", 22, 3);
    Episode wedding(1, "The Wedding", 22, 4);

    //Crear al manager
    StreamingManager list; 

    //Agregar videos a la lista
    list.addVideo(&CaptainAmerica);
    list.addVideo(&TheSoundOfMusic);
    list.addVideo(&ParksAndRec); 
    list.addVideo(2, &GrownUps);
    list.addVideo(&Friends);

    //Imprimir videos
    list.printVideos(); 

    //Imprimir películas 
    cout << "Lista de pelis" << endl; 
    list.printMovies(); 

    //Imprimir Series
    cout << "Lista de Series" << endl; 
    list.printSeries(); 

    //Imprimir lista de episodios de una serie
    cout << "Lista de serie sin episodios" << endl; 
    list.printSerieEpisodes(&ParksAndRec);
    list.addEpisode(&ParksAndRec, &pilot); 
    list.addEpisode(&ParksAndRec, &wedding);
    cout << "Lista de serie con episodios" << endl; 
    list.printSerieEpisodes(&ParksAndRec); 

    //Imprimir rating promedio de los episodios de una serie
    cout << "Rating de Parks and Recreation: " << list.episodesMean(&ParksAndRec) << endl;
    cout << endl; 

    //Buscar una película
    list.searchVideosByName("Captain America"); 
    cout << endl; 

    //Buscar una serie
    list.searchVideosByName("Parks and Recreation"); 
}
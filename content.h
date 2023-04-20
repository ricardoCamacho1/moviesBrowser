class Content
{
private:
    
public:
    Content(string title = " Title", string type = "Movie", string duration = "0 season", string release_year = "2020", string description = "No description", string rating = "0") // Argumentos escensiales para cada contenido audo visual
    {
        this->title = title;
        this->duration = duration;
        this->release_year = release_year;
        this->description = description;
        this->type = type;
        this->rating = rating;
    }

    friend ostream &operator<<(ostream &salida, const Content &producto); // Funcion friend para modificador de operador
    string getTitle() const
    {
        return title;
    }

    string getDuration() const
    {
        return duration;
    }

    string getDescription() const
    {
        return description;
    }
    string getType() const
    {
        return type;
    }

    string getYear() const
    {
        return release_year;
    }
    string getRating() const
    {
        return rating;
    }
protected:
string title, duration, description, type, release_year, rating;

};
ostream &operator<<(ostream &salida, const Content &contenido)
{
    salida << contenido.title << ", " << contenido.type << ", " << contenido.duration << ", " << contenido.release_year << ", " << contenido.description << ", " << contenido.rating;
    return salida;
} // Modificador de operador, para la salida de los datos del contenido creado.
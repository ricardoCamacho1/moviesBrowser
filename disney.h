class DisneyInventario : public Content
{
private:
   
public:
    DisneyInventario(string title = " Title", string type = "Movie", string duration = "0 season", string release_year = "2020", string description = "No description", string rating = "0") // Argumentos escensiales para cada contenido audo visual
    {
        this->title = title;
        this->duration = duration;
        this->release_year = release_year;
        this->description = description;
        this->type = type;
        this->rating = rating;
    }

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
};

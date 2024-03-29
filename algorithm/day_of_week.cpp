int zeller(const struct Date* date){
    int month = date->month;
    int year = date->year;
    
    if(date->month<3){
        year--;
        month+=12;
    }
    
    int yr = year%100;
    int century = year/100;
    int result = date->day;
    result += 13*(month+1) / 5;
    result += yr;
    result += yr/4;
    result += century/4;
    result -= 2*century;
    result = result % 7;
    return result;
}

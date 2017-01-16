
//
// Julie Salah
// Fractal Tree
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace sf;

const float PI = 3.1415926536f;



class vectorTree
{
public:
    int x, y;
    
    vectorTree()
    {
       x = 0;
        y= 0;
    }
    vectorTree( int a, int b )
    {
        x = a;
        y = b;
    }
    
    void set( int a, int b )
    {
        x = a;
        y = b;
    }
    void rotate( float angle_r )
    {
        float _x = static_cast<float>( x ),
        _y = static_cast<float>( y ),
	       s = sinf( angle_r ),
	       c = cosf( angle_r ),
	       a = _x * c - _y * s,
	       b = _x * s + _y * c;
        
        x = static_cast<int>( a );
        y = static_cast<int>( b );
    }
    
    
};

class fractalTree
{
public:
    fractalTree(int, int)
    {
        int x = 0;
        int y = 0;
    }
    float toRadian( float degree )
    {
        return degree * ( PI / 180.0f );
    }
    
    void create()
    {
 
        float length = 130.0f;
        
        vectorTree pos(400, 1);
        move(pos.x, pos.y);
        pos.y -= static_cast<int>(length);
        setPosition(pos.x, pos.y);
        
        drawTree( &pos, length, 0);
        drawTree( &pos, length, 0);
    }
    
private:
    void drawTree( vectorTree* pos, float length, float a)
    {
        length *= .75f;
        if( length < 2.0f ) return;
        
        vectorTree pos2( 0, static_cast<int>(length) );

        
        pos2.rotate( a );
        pos2.x += pos->x; pos2.y = pos->y - pos2.y;
        
        pos2.move(pos2.x, pos2.y );
        
        drawTree( &pos2, length, a);
        drawTree( &pos2, length, a);
    }
    
   
};

int main(int, char const**)
{
    // Create the main window
    RenderWindow window(VideoMode(800, 600), "Fractal Tree");
    window.clear(sf::Color::Black);
    
    fractalTree tree;
    
    RectangleShape line(fractalTree(500, 1));
    line.setPosition(400,1);
    window.draw(line);
    
    
    
    window.draw(tree);
    
    window.display();
    
    sleep (seconds (5));
    return 0;
    
}

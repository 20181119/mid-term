#pragma once
#include <string>
using namespace std;
class loadParams
{
public:
loadParams(int x,int y,int width,int height, string textureID)
:m_x(x),
 m_y(y),
 m_width(width),
 m_height(height),
 m_textureID(textureID){}

int getX() const {return m_x;}
int getY() const {return m_y;}
int getwidth() const {return m_width;}
int getheight() const {return m_height;}
string gettextureID() const {return m_textureID;}

private:
int m_x,m_y;
int m_width,m_height;

string m_textureID;

};
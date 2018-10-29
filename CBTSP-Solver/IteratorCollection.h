#pragma once

#include <unordered_map>
#include <map>

template<class VERTEX_TYPE> //wir brauchen ein template, damit wir die interaktion zwischen der Klasse Vertex 
//und ihrem iterator außerhalb der Vertexklasse selbst definieren können, ohne in infinite Abhängigkeiten zu kommen. 
//Das ist lediglich ein Trick, um schöneren Code zu bekommen und die Iteratordefinition außerhalb definiert werden kann.
class const_iterator_Vertex //this makes Vertex feel like a real container; we can iterate trough his neighbours using range-based for-loops, e.g. (const auto& neighbour: vertex). 
{
	using const_iterator_intern = typename std::multimap<double,const VERTEX_TYPE*>::const_iterator;
public:
	const_iterator_Vertex(const_iterator_intern it) : it(it) {};
	const_iterator_Vertex operator++() { ++it; return *this; }
	const_iterator_Vertex operator--() { --it; return *this; }
	const VERTEX_TYPE& operator*() const { return *it->second; }
	friend bool operator==(const_iterator_Vertex l, const_iterator_Vertex r) { return l.it == r.it; }
	friend bool operator!=(const_iterator_Vertex l, const_iterator_Vertex r) { return l.it != r.it; }
	//friend std::ostream& operator<<(std::ostream& os, const Vertex&);
private:
	const_iterator_intern it;
};

template<class VERTEX_TYPE> 
class const_iterator_Graph //this makes Graph feel like a real container; we can iterate trough his Vertices using range-based for-loops, e.g. (const auto& neighbour: vertex). 
{
	using const_iterator_intern = typename std::unordered_map<int, VERTEX_TYPE>::const_iterator;
public:
	const_iterator_Graph(const_iterator_intern it) : it(it) {};
	const_iterator_Graph operator++() { ++it; return *this; }
	const_iterator_Graph operator--() { --it; return *this; }
	const VERTEX_TYPE& operator*() const { return it->second; }
	friend bool operator==(const_iterator_Graph l, const_iterator_Graph r) { return l.it == r.it; }
	friend bool operator!=(const_iterator_Graph l, const_iterator_Graph r) { return l.it != r.it; }
private:
	const_iterator_intern it;
};

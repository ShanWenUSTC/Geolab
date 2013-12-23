#pragma once
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Simple_cartesian.h>
#include <Eigen/Dense>

typedef CGAL::Simple_cartesian<double>		Kernel;
typedef CGAL::Polyhedron_3<Kernel>			Polyhedron;
typedef Kernel::Point_3						Point;
typedef Polyhedron::Vertex_iterator			Vertex_iterator;
typedef Polyhedron::Face_iterator			Face_iterator;
typedef Polyhedron::Halfedge_around_vertex_circulator 
	Halfedge_vertex_circulator;
typedef Polyhedron::Halfedge_around_facet_circulator
	Halfedge_facet_circulator;
typedef Eigen::Vector3d						vec;

using std::vector;
using std::map;

class MyPolyhedron : public Polyhedron
{
public:
	MyPolyhedron(void);
	~MyPolyhedron(void);

	void SetId();
	int FaceId(Face_iterator fiter);
	int VertexId(Vertex_iterator viter);
	Face_iterator FaceIterator(int findex);
	Vertex_iterator VertexIterator(int vindex);

	void setFaceNormal();
	void setVertexNormal();

	vector<vec> facenormal_;
	vector<vec> vertexnormal_;

private:
	map<int, Vertex_iterator> vindexToIter_;
	map<int, Face_iterator> findexToIter_;
	map<Vertex_iterator, int> viterToIndex_;
	map<Face_iterator, int> fiterToIndex_;
};
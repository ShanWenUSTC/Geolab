#include "StdAfx.h"
#include "MyPolyhedron.h"

MyPolyhedron::MyPolyhedron() : Polyhedron()
{

}

MyPolyhedron::~MyPolyhedron()
{

}

int MyPolyhedron::FaceId(Face_iterator fiter)
{
	return fiterToIndex_[fiter];
}

int MyPolyhedron::VertexId(Vertex_iterator viter)
{
	return viterToIndex_[viter];
}

Face_iterator MyPolyhedron::FaceIterator(int findex)
{
	return findexToIter_[findex];
}

Vertex_iterator MyPolyhedron::VertexIterator(int vindex)
{
	return vindexToIter_[vindex];
}

void MyPolyhedron::SetId()
{
	int index=0;
	for (Vertex_iterator viter = vertices_begin();
		viter != vertices_end(); viter++)
	{
		Point n = viter->point();
		vindexToIter_[index] = viter;
		viterToIndex_[viter] = index;
		index++;
	}

	index = 0;
	for (Face_iterator fiter = facets_begin();
		fiter != facets_end(); fiter++)
	{
		findexToIter_[index] = fiter;
		fiterToIndex_[fiter] = index;
		index++;
	}
}

void MyPolyhedron::setFaceNormal()
{
	Point p1, p2, p3;

	facenormal_.clear();
	for (Face_iterator fiter = facets_begin();
		fiter != facets_end(); fiter++)
	{
		Halfedge_facet_circulator fcir = fiter->facet_begin();
		p1 = fcir->vertex()->point();
		p2 = fcir->next()->vertex()->point();
		p3 = fcir->next()->next()->vertex()->point();

		vec v1(p2.x()-p1.x(), p2.y()-p1.y(), p2.z()-p1.z());
		vec v2(p3.x()-p2.x(), p3.y()-p2.y(), p3.z()-p2.z());
		vec vn = v1.cross(v2);
		//cout<<"fn test "<<vn[0]<<' '<<vn[1]<<' '<<vn[2]<<endl;
		facenormal_.push_back(vn);
	}	
}

void MyPolyhedron::setVertexNormal()
{
	for (Vertex_iterator viter = vertices_begin();
		viter != vertices_end(); viter++)
	{
		Halfedge_vertex_circulator vcir = viter->vertex_begin();

		vec vn(0,0,0);
		int findex;
		do 
		{
			Face_iterator fiter = vcir->facet();
			findex = FaceId(fiter);
			vn += facenormal_[findex];
		} while (++vcir != viter->vertex_begin());

		int nsize = circulator_size(vcir);		
		vn = vn/nsize;
		//cout<<"vn test "<<vn[0]<<' '<<vn[1]<<' '<<vn[2]<<endl;
		vertexnormal_.push_back(vn);
	}
}

// Anirudh Sathish 
// Menu driven program to calculate area's and volume's of various
// gemoetric shapes by making use of the friend, inline and this pointer concepts

#include<iostream>

using namespace std ;

class Volume ;


/*----------------------------------------------*/
/* Describing a class area*/
class Area
{
	private: 
	  int length ;
	  int breadth ;
	  int radius;
	  int area_rectangle ;
	  float area_circle ;
	  
	public :
		Area() // constructor 
		{
			length = 1 ;
			breadth = 1 ;
			area_rectangle = 1;
			radius = 1 ;
			area_circle = 1 ;
		}
		void displayData()
		{
			area_rectangle = length *breadth;
			cout <<"The area of the rectangle with sides 1 are "<< area_rectangle <<endl ;
		}
		void displayCdata()
		{
			area_circle = 3.14*radius*radius ;
			cout <<"The area of the  default circle is  "<< area_circle <<endl ;
		}
		friend void valueAddition (Area &a , Volume &v  );
		friend void valueCircle (Area &a, Volume &v );
 } ;
 
 /*-----------------------------------------------------------------*/
 /*------------Describing class Volume-------------------*/
 class Volume 
 {
 	private :
 		int length ;
 		int breadth ;
	    int radius;
	    int height;
	    int volume_cuboid ;
	    float volume_sphere ;
	public:
		Volume()
		{
			length = 1 ;
			breadth = 1 ;
			height = 1 ;
			volume_cuboid = 1;
			radius = 1 ;
			volume_sphere = 1 ;
		}
		void volumeCuboid()
		{
			volume_cuboid = length *breadth*height ;
			cout <<"The volume of the cuboid  "<< volume_cuboid <<endl ;
			cout<<endl ;
		}
		void volumeSphere()
		{
			volume_sphere = (4*3.14*radius*radius*radius)/3.0;
			cout<<"The volume of the sphere is "<<volume_sphere <<endl ;
			cout<<endl ;
		}
		void compare()
		{
			if(this->volume_sphere > this->volume_cuboid)
			{
				cout<<" The volume of the sphere is greater "<<endl ;
				cout<<"The volume of the sphere is "<<this->volume_sphere<<endl ;
				cout<<endl ;
			}
			else if(this->volume_sphere < this->volume_cuboid)
			{
				cout<<" The volume of the cuboid is greater "<<endl ;
				cout<<"The volume of the cuboid is "<<this->volume_cuboid<<endl;
				cout<<endl ;
			}
			else
			{
				cout<<" The volume both is equal  "<<endl ;
				cout<<"The volume of the sphere is "<<this->volume_sphere <<endl;
				cout<<"The volume of the cuboid is "<<this->volume_cuboid<<endl ;
				cout<<endl ;
			}
		}
		void compareCuboids( int volume_cuboid )
		{
		   cout<<" THe volume of the cuboid 2 is "<<volume_cuboid<<endl ;
		   cout<<" The volume of the inital cuboid, cuboid 1 is   "<<this->volume_cuboid <<endl ;
		   cout<<endl ;
		   
		   if(volume_cuboid > this->volume_cuboid )
		   {
		   	cout<<" The volume of the cuboid 2 is greater "<<endl;
		    cout<<" THe volume of the cuboid 2 is "<<volume_cuboid<<endl ;
		   }
		   else if(volume_cuboid < this->volume_cuboid )
		   {
		   	cout<<" The volume of the cuboid 1 is greater "<<endl;
		    cout<<" THe volume of the cuboid 1 is "<<this->volume_cuboid<<endl ;
		   }
		   else
		   {
		   	cout<<" The volume of the cuboids are equal  "<<endl;
		    cout<<" The volume of cuboid 1 is "<<this->volume_cuboid<<endl ;
		    cout<<" The volume of cuboid 2 is "<<volume_cuboid<<endl ;
		   }
		}
		void compareSpheres(int volume_sphere)
		{
		   cout<<" THe volume of the sphere 2 is "<<volume_sphere<<endl ;
		   cout<<" The volume of the inital sphere, sphere 1 is   "<<this->volume_sphere <<endl ;
		   cout<<endl ;
		   
		   if(volume_sphere > this->volume_sphere )
		   {
		   	cout<<" The volume of the sphere 2 is greater "<<endl;
		    cout<<" THe volume of the sphere 2 is "<<volume_sphere<<endl ;
		   }
		   else if(volume_sphere < this->volume_sphere )
		   {
		   	cout<<" The volume of the sphere 1 is greater "<<endl;
		    cout<<" THe volume of the sphere 1 is "<<this->volume_sphere<<endl ;
		   }
		   else
		   {
		   	cout<<" The volume of the cuboids are equal  "<<endl;
		    cout<<" The volume of sphere 1 is "<<this->volume_sphere<<endl ;
		    cout<<" The volume of sphere 2 is "<<volume_sphere<<endl ;
		   }
		}

		friend void valueAddition (Area &a , Volume &v );
		friend void valueCircle (Area &a, Volume &v );
 };
 
 inline void valueAddition (Area &a, Volume &v )
 {  
   int num ;
   cout <<" confirm operation by chosing \n 2.For area  \n 3.For volume "<<endl ;
   cin>>num;

   if(num == 2)
   {
   	  cout<<" Enter the required length " << endl ;
      cin >>a.length;
      cout<<" Enter the required breadth " << endl ;
      cin >>a.breadth;
 	  a.area_rectangle = a.length *a.breadth ;
 	  cout <<"The area of the rectangle is "<< a.area_rectangle <<endl ;
 	  cout<<endl;
   }
   if(num == 3)
   {
   	  cout<<" Enter the required length " << endl ;
      cin >>v.length;
      cout<<" Enter the required breadth " << endl ;
      cin >>v.breadth;
      cout<<" Enter the required height " << endl ;
      cin >>v.height ;
      v.volume_cuboid = v.length *v.breadth*v.height ;
 	  cout <<"The volume of the cuboid is  "<< v.volume_cuboid <<endl ;
 	  cout<<endl;
   }
    
 }
 inline void valueCircle( Area &a, Volume &v  )
 {
 	int num ;
    cout <<" confirm operation by chosing \n 2.For area  \n 3.For volume "<<endl ;
    cin>>num;
 	if(num == 2)
 	{
 		cout<<" Enter the required radius " << endl ;
        cin >>a.radius;
        a.area_circle = 3.14*a.radius*a.radius ;
        cout <<"The area of the circle is "<< a.area_circle <<endl ;
        cout<<endl;
	 }
	if(num == 3)
	{
		cout<<" Enter the required radius " << endl ;
        cin >>v.radius;
        v.volume_sphere = (4*3.14*v.radius*v.radius*v.radius)/3.0;
        cout <<"The volume of the sphere is  "<< v.volume_sphere <<endl ;
        cout<<endl;
	}
 	
 }
 int main()
 {
 	// Creating objects
 	Area a1;  
 	Volume v1;
 	int choice;
 	int vol_s ;
 	int vol_c ;
 	cout<<endl;
 	while( 1 )  //menu driven program
    {
    	cout<<"Menu "<<endl ;
    	cout<<endl ;
        cout<<"1.Area of rectangle with no parameters entered "<<endl;
        cout<<"2.Area of rectangle with parameters "<<endl;
        cout<<"3.Area of circle with no parameters entered "<<endl;
        cout<<"4.Area of circle with parameters "<<endl;
        cout<<"5.Volume of cuboid with no parameters entered "<<endl;
        cout<<"6.Volume of cuboid with parameters "<<endl;
        cout<<"7.Volume of sphere with no parameters entered "<<endl;
        cout<<"8.Volume of shpere with parameters "<<endl;
        cout<<"9.Compare the volumes of the sphere and the cube "<<endl;
        cout<<"10.Compare two cuboids  "<<endl ;
        cout<<"11.Compare two spheres "<<endl ;
        cout<<"12.Exit "<<endl ;
        
        cout<<endl ;
        
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice) // using switch statements 
        {
            case 1: //Case where no parameters are taken in for finding the area of the rectangle  
                   a1.displayData();
				   break ;
            case 2: // Case where parameters are taken to find the area of the rectangle
				valueAddition(a1, v1);
				break;
			case 3: //Case where no parameters are taken to find the area of the circle
                a1.displayCdata();
				   break ;
            case 4: // Case where parameters are taken to find the area of the circle  
				valueCircle(a1, v1);
				break;
			case 5: //Case where no parameters are taken to find the volume of the cuboid 
                v1.volumeCuboid();
				   break ;
            case 6: // Case where parameters are taken to find the volume of the cuboid 
				valueAddition(a1, v1);
				break;
			case 7: //Case where no parameters are taken to find the volume of the sphere 
                 v1.volumeSphere();
				   break ;
            case 8: // Case where parameters are taken to find the volume of the sphere 
				  valueCircle(a1, v1);
				break;
			case 9: // Case to compare the volumes of the sphere and cuboid 
				  v1.compare();
				break;
		    case 10: // Case to compare the volumes of the cuboid
				  {
				  	cout<<" Enter the value of cuboid 2 "<<endl ;
				  	cin>>vol_c;
				  	v1.compareCuboids(vol_c);
				  	break;
				  }
			case 11: // Case to compare the volumes of the sphere
				  {
				  	cout<<" Enter the value of sphere 2 "<<endl ;
				  	cin>>vol_s;
				  	v1.compareSpheres(vol_s);
				  	break;
				  }
				
            case 12: // exit 
				exit(1);
				break;
                
            default:  // case of wrong inputs
                cout<<"\nWrong choice, try again!\n";
                break;
        }
    }
    return 0 ;
 }

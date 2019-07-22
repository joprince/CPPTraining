#include "CFile.h"

CFile::CFile( void )
{

}
void CFile::Write( CStudent data )
{
    ostorage.open("STUDENT.dat", ios::out | ios::binary | ios::ate );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    ostorage.write( reinterpret_cast<const char*>( &data ),sizeof( data ) );
    ostorage.flush();
    ostorage.close();
}

CStudent CFile::GetData( int nAdmNo )
{
    CStudent temp;

    istorage.open( "STUDENT.dat", ios::in | ios::binary );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    istorage.seekg( 0, ios::beg );
    while( !istorage.eof() )
    {
        istorage.read( ( char* )&temp,sizeof( temp ) );
        if( nAdmNo == temp.GetAdmNo() )
        {
            return temp;
        }
        else
        {
            //unimplemented
        }
    }
    istorage.close();
    return temp;
}

void CFile::ViewAll( void )
{
    CStudent temp;

    istorage.open( "STUDENT.dat", ios::in | ios::binary );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    cout<<istorage.tellp()<<"\n";
    istorage.clear();
    istorage.seekg( 0, ios::beg );
    while( istorage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        cout<<"in\n";
        temp.ViewTab();
        cout<<"after\n";
    }
    cout<<istorage.tellg();
    istorage.close();
}

void CFile::ClearSpec( int nAdmNo )
{
    CStudent temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( istorage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }
}

void CFile::ClearFile( void )
{
    istorage.close();
    ostorage.close();
    remove( "STUDENT.dat" );
    ostorage.open("STUDENT.dat", ios::out | ios::binary );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    ostorage.close();
}

CFile::~CFile( void )
{
    ostorage.close();
    istorage.close();
}

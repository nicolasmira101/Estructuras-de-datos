#include "oficina_reparto.h"
#include <string>

using namespace std;

OficinaReparto::OficinaReparto(){}

OficinaReparto::OficinaReparto(string codigo, string nombre, string direccion, string ciudad){
	this->codigo = codigo;
	this->nombre = nombre;
	this->direccion = direccion;
	this->ciudad = ciudad;
}

//--------------------------------------------------------------------------------------------------------
//getters

string OficinaReparto::getCodigo(){
	return this->codigo;
}

string OficinaReparto::getNombre(){
	return this->nombre;
}

string OficinaReparto::getDireccion(){
	return this->direccion;
}

string OficinaReparto::getCiudad(){
	return this->ciudad;
}

list<RegionReparto> OficinaReparto::getRegiones(){
	return this->regiones;
}

//--------------------------------------------------------------------------------------------------------		
//setters
		
void OficinaReparto::setCodigo(string codigo){
	this->codigo = codigo;
}

void OficinaReparto::setNombre(string nombre){
	this->nombre = nombre;
}

void OficinaReparto::setDireccion(string direccion){
	this->direccion = direccion;
}

void OficinaReparto::setCiudad(string ciudad){
	this->ciudad = ciudad;
}

void OficinaReparto::setRegiones(list<RegionReparto> regiones){
	this->regiones = regiones;
}

void OficinaReparto::agregarRegion(RegionReparto regionReparto){
	this->regiones.push_back(regionReparto);
}

//--------------------------------------------------------------------------------------------------------

RegionReparto OficinaReparto::buscarRegion(string codigoRegion){
	
	RegionReparto regionReparto;
	regionReparto.setCodigo("-1");

	for(list< RegionReparto >::iterator it = this->regiones.begin(); it != this->regiones.end( ); it++){
		if( codigoRegion == (*it).getCodigo() ){
			regionReparto = *it;
			break;
		}
	}
	
	return regionReparto;
}

//--------------------------------------------------------------------------------------------------------

void OficinaReparto::agregarPaquete(Paquete paquete){
	RegionReparto region = this->buscarRegion( paquete.getRegionReparto() );
	if( region.getCodigo() != "-1" ){ //el paquete se va a repartir en una de las regiones que maneja esta oficina, por tanto no se debe reubicar
		paquete.setRepartido();		//establece el paquete como repartido
	}
	this->paquetes.push_back(paquete);
}

//--------------------------------------------------------------------------------------------------------

std::list<Paquete> OficinaReparto::getPaquetes(){
	return this->paquetes;
}

//--------------------------------------------------------------------------------------------------------

Paquete OficinaReparto::buscarPaquete(string numeroGuia){
	
	Paquete paquete;
	paquete.setNumeroGuia("-1");
	
	for(list< Paquete >::iterator it = this->paquetes.begin(); it != this->paquetes.end(); it++){
		if( numeroGuia == (*it).getNumeroGuia() ){
			paquete = *it;
			break;
		}
	}
	
	return paquete;	
}

//--------------------------------------------------------------------------------------------------------

std::list<Paquete> OficinaReparto::getPaquetesARepartir(){
	list< Paquete > paquetesARepartir;
	for(list< Paquete >::iterator it = this->paquetes.begin(); it != this->paquetes.end(); it++){
		if( (*it).getRepartido() == false ){ // debe ser repartido
			paquetesARepartir.push_back( *it );
		}
	}
	return paquetesARepartir;
}

//--------------------------------------------------------------------------------------------------------

std::list<Paquete> OficinaReparto::getPaquetesRepartidos(){
	list< Paquete > paquetesRepartidos;
	for(list< Paquete >::iterator it = this->paquetes.begin(); it != this->paquetes.end(); it++){
		if( (*it).getRepartido() == true ){ //si se repartió acá
			paquetesRepartidos.push_back( *it );
		}
	}
	return paquetesRepartidos;
}

//--------------------------------------------------------------------------------------------------------

void OficinaReparto::eliminarPaquete(std::string numeroGuia){
	list< Paquete >::iterator it;
	for(it = this->paquetes.begin(); it != this->paquetes.end(); it++){
		if( (*it).getNumeroGuia() == numeroGuia ){ 
			break;
		}
	}
	this->paquetes.erase(it);
}
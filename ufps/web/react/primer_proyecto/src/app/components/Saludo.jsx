'use client';
import { useState, useEffect} from "react";

export function Menu() {
  const [nombre, setNombre] = useState("")
  
  return (
    <div className="flex flex-col items-center gap-4 mt-8">
      <input id="pokemonBuscar" type="text" placeholder="Escribe un pokemon" className="border p-2 rounded mt-2"/>
      <button onClick={() => {
        const nompok = document.getElementById("pokemonBuscar").value;
        if(nompok.trim() === "") return 
        setNombre(nompok)
      }}>Buscar Pokemon</button>
     <BuscadorPokemon nombre={nombre}/>
    </div>
  );
}

export function BuscadorPokemon({ nombre }) {
  if(nombre.trim() === "") return null;
  const [pokemon, setPokemon] = useState(null); 
  const [error, setError] = useState(null);

  useEffect(() => {
    setError(null);
    setPokemon(null);

    fetch(`https://pokeapi.co/api/v2/pokemon/${nombre.toLowerCase()}`)
      .then((res) => {
        if (!res.ok) {
          throw new Error("Pokémon no encontrado 😢");
        }
        return res.json();
      })
      .then((data) => {
        setPokemon(data);
      })
      .catch((err) => {
        setError(err.message);
      });
  }, [nombre]);

  return (
    <div className="flex flex-col items-center gap-4 mt-8">
      {
        error ? (<h2 className="text-red-500">{error}</h2>) :
        !pokemon ? (<h2>Cargando Pokémon...</h2>) :
        (
          <div className="flex flex-col items-center gap-4">
            <h1 className="text-2xl font-semibold capitalize">{pokemon.name}</h1>
            <img
              src={pokemon.sprites.front_default}
              alt={pokemon.name}
              width={200}
              height={200}
            />
          </div>
        )
      }
    </div>
  );
}
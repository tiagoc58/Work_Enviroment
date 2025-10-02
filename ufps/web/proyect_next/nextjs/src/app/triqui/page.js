"use client";
import { useState } from 'react';

function Square({ value, onSquareClick }) {
  return (
    <button className="square bg-[#FFF4E6] m-5 h-30 w-30 rounded-lg shadow-lg text-[50px] font-bold text-[#C75B39]" onClick={onSquareClick}>
      {value}
    </button>
  );
}

function Board({ xIsNext, squares, onPlay }) {
  function handleClick(i) {
    if (calculateWinner(squares) || squares[i]) {
      return;
    }
    const nextSquares = squares.slice();
    if (xIsNext) {
      nextSquares[i] = 'X';
    } else {
      nextSquares[i] = 'O';
    }
    onPlay(nextSquares);
  }

  const winner = calculateWinner(squares);
  let status;
  if (winner) {
    status = winner +  " JUST WON!!";
  } else if (!squares.includes(null)) {
  status = "It's a draw!";
  } else {
    status ="It's " + (xIsNext ? 'X' : 'O') + " turn";
  }

  return (
    <>
      <div className="status font-bold text-[#5B4636] text-[40px]">{status}</div>
      <div className="grid grid-cols-3 px-6">
        {squares.map((sq, i) => (
          <Square key={i} value={sq} onSquareClick={() => handleClick(i)} />
        ))}
      </div>
    </>
  );
}

export default function Game() {
  const [history, setHistory] = useState([Array(9).fill(null)]);
  const [currentMove, setCurrentMove] = useState(0);
  const xIsNext = currentMove % 2 === 0;
  const currentSquares = history[currentMove];

  function handlePlay(nextSquares) {
    const nextHistory = [...history.slice(0, currentMove + 1), nextSquares];
    setHistory(nextHistory);
    setCurrentMove(nextHistory.length - 1);
  }

  function jumpTo(nextMove) {
    setCurrentMove(nextMove);
  }

  const moves = history.map((squares, move) => {
    let description;
    if (move > 0) {
      description = 'Go to move #' + move;
    } else {
      description = 'Go to game start';
    }
    return (
      <li className="mb-5 px-10 py-2 font-bold bg-[#BFA6A0] rounded-lg shadow-lg text-[40px] text-[#F8F3EC] flex justify-center" key={move}>
        <button onClick={() => jumpTo(move)}>{description}</button>
      </li>
    );
  });

  return (
    <div className="game bg-[#AC9362] flex justify-center p-10 h-250">
      <div className="game-board place-items-center py-5 mx-10 bg-[#E7C3A8] rounded-lg shadow-lg h-150">
        <Board xIsNext={xIsNext} squares={currentSquares} onPlay={handlePlay} />
      </div>
      <div className="game-info">
        <ol className="mx-10 h-100">{moves}</ol>
      </div>
    </div>
  );
}

function calculateWinner(squares) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];
  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
}

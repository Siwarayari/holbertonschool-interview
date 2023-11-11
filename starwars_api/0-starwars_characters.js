#!/usr/bin/node
const url = 'https://swapi-api.hbtn.io/api/films/';
const request = require('request');

request(url + process.argv[2] + '/', async (error, response, body) => {
  if (error) throw error;
  const film = JSON.parse(body);
  const charUrls = film.characters;

  for (const charUrl of charUrls) {
    await new Promise(function (resolve, reject) {
      request(charUrl, function (error, request, body) {
        if (error) throw error;
        const data = JSON.parse(body);
        const character = data.name;
        console.log(character);
        resolve();
      });
    });
  }
});

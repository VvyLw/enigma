// random.js
"use strict";
const generate = () => {
    const people = document.getElementById('num').value;
    if(isNaN(people)) {
        console.error("入力された値が数字ではありません。");
        return;
    }
    const num = [];
    const res = [];
    for(let i = 0; ++i <= 100;) {
        num.push(i);
    }
    for(let i = 0; i < parseInt(people); ++i) {
        const id = Math.floor(Math.random() * num.length);
        res.push(num[id]);
        num.splice(id, 1);
    }
    return res;
};
document.getElementById('generate').addEventListener('click', () => {
    const rand = generate();
    const htmlRand = document.getElementById('result');
    htmlRand.textContent = "あなたの数字: " + rand.join(', ');
});
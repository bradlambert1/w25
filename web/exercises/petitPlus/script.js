const button = document.getElementById("button");
const text = document.getElementById("text");

function addToList(input) {
  const list = document.getElementById("list");
  const span = document.createElement("span");
  list.appendChild(span);
  span.innerHTML = input;

  const button = document.createElement("button");
  span.appendChild(button);

  button.onclick = function (span) {
    span.innerHTML = "test";
  };
}

button.onclick = function test() {
  console.log(text.value);
  addToList(text.value);
};

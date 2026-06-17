const form = document.getElementById("transaction-form");
const list = document.getElementById("transaction-list");
const balance = document.getElementById("balance");

let transactions =
    JSON.parse(localStorage.getItem("transactions")) || [];

function updateUI() {
    list.innerHTML = "";

    let total = 0;

    transactions.forEach((transaction, index) => {
        const li = document.createElement("li");

        li.innerHTML =
            `${transaction.description}
         - ₹${transaction.amount}
         (${transaction.type})`;

        list.appendChild(li);

        if (transaction.type === "income")
            total += transaction.amount;
        else
            total -= transaction.amount;
    });

    balance.textContent = `₹${total}`;

    localStorage.setItem(
        "transactions",
        JSON.stringify(transactions)
    );
}

form.addEventListener("submit", function (e) {
    e.preventDefault();

    const description =
        document.getElementById("description").value;

    const amount =
        Number(document.getElementById("amount").value);

    const type =
        document.getElementById("type").value;

    transactions.push({
        description,
        amount,
        type
    });

    updateUI();

    form.reset();
});

updateUI();
// JavaScript code for countdown timer
const countdownElement = document.getElementById("countdown");

// Set the date we're counting down to
const countdownDate = new Date();
countdownDate.setMinutes(countdownDate.getMinutes() + 30); // 30 minutes from now

// Update the countdown every second
const countdownInterval = setInterval(updateCountdown, 1000);

function updateCountdown() {
    // Get the current date and time
    const now = new Date().getTime();

    // Calculate the distance between now and the countdown date
    const distance = countdownDate - now;

    // If the countdown is over, display a message
    if (distance <= 0) {
        clearInterval(countdownInterval);
        countdownElement.innerHTML = "Offer expired!";
        return;
    }

    // Calculate remaining time
    const hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((distance % (1000 * 60)) / 1000);

    // Display the countdown
    countdownElement.innerHTML = `Offer ends in ${hours}h ${minutes}m ${seconds}s`;
}
